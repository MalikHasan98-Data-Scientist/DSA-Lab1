#include <vector>
#include <iostream>
using namespace std;

// This is a shortcut so we don't have to type "vector<vector<int>>" every time.
// We will just call it "Matrix".
typedef vector<vector<int>> Matrix;

// Helper function to add two matrices
Matrix addMatrices(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n, 0)); // Create an n x n matrix filled with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

// Helper function to subtract two matrices
Matrix subMatrices(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// Standard (Naive) Matrix Multiplication (Used for small matrices and comparison)
Matrix multiplyNaive(Matrix A, Matrix B, int n) {
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

// Strassen's Algorithm
Matrix strassen(Matrix A, Matrix B, int n) {
    // Base Case: If matrix is small (2x2 or smaller), just use normal multiplication
    if (n <= 2) {
        return multiplyNaive(A, B, n);
    }

    int half = n / 2;

    // Create 4 quadrants for A and B (top-left, top-right, bottom-left, bottom-right)
    Matrix A11(half, vector<int>(half)), A12(half, vector<int>(half));
    Matrix A21(half, vector<int>(half)), A22(half, vector<int>(half));
    Matrix B11(half, vector<int>(half)), B12(half, vector<int>(half));
    Matrix B21(half, vector<int>(half)), B22(half, vector<int>(half));

    // Split the matrices into quadrants
    for (int i = 0; i < half; i++) {
        for (int j = 0; j < half; j++) {
            A11[i][j] = A[i][j];             A12[i][j] = A[i][j + half];
            A21[i][j] = A[i + half][j];      A22[i][j] = A[i + half][j + half];
            B11[i][j] = B[i][j];             B12[i][j] = B[i][j + half];
            B21[i][j] = B[i + half][j];      B22[i][j] = B[i + half][j + half];
        }
    }

    // Calculate the 7 special Strassen products
    Matrix M1 = strassen(addMatrices(A11, A22, half), addMatrices(B11, B22, half), half);
    Matrix M2 = strassen(addMatrices(A21, A22, half), B11, half);
    Matrix M3 = strassen(A11, subMatrices(B12, B22, half), half);
    Matrix M4 = strassen(A22, subMatrices(B21, B11, half), half);
    Matrix M5 = strassen(addMatrices(A11, A12, half), B22, half);
    Matrix M6 = strassen(subMatrices(A21, A11, half), addMatrices(B11, B12, half), half);
    Matrix M7 = strassen(subMatrices(A12, A22, half), addMatrices(B21, B22, half), half);

    // Combine the results into the final quadrants
    Matrix C11 = addMatrices(subMatrices(addMatrices(M1, M4, half), M5, half), M7, half);
    Matrix C12 = addMatrices(M3, M5, half);
    Matrix C21 = addMatrices(M2, M4, half);
    Matrix C22 = addMatrices(subMatrices(addMatrices(M1, M3, half), M2, half),