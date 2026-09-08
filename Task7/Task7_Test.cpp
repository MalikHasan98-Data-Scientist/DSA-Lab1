#include <iostream>
#include <vector>
#include <cstdlib> // For random numbers
#include "Task7_Impl.cpp"
using namespace std;

typedef vector<vector<int>> Matrix;

// Helper function to print a matrix nicely
void printMatrix(Matrix mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    cout << "--- Task 7: Strassen's Matrix Multiplication ---" << endl;

    // Test 4.a: 2x2 matrix multiplication
    cout << "\nTest 4.a: 2x2 Matrices" << endl;
    Matrix A2 = {{1, 2}, {3, 4}};
    Matrix B2 = {{5, 6}, {7, 8}};
    cout << "Result:" << endl;
    printMatrix(strassen(A2, B2, 2), 2);

    // Test 4.b: 4x4 matrix multiplication
    cout << "\nTest 4.b: 4x4 Matrices" << endl;
    Matrix A4 = {{1,0,0,1}, {0,1,0,0}, {0,0,1,0}, {1,0,0,1}};
    Matrix B4 = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,16}};
    cout << "Result:" << endl;
    printMatrix(strassen(A4, B4, 4), 4);

    // Test 4.c: Random 4x4 values compared with naive multiplication
    cout << "\nTest 4.c: Comparing Strassen vs Naive (Random 4x4)" << endl;
    int n = 4;
    Matrix RandA(n, vector<int>(n)), RandB(n, vector<int>(n));
    
    // Fill with random numbers between 0 and 9
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            RandA[i][j] = rand() % 10;
            RandB[i][j] = rand() % 10;
        }
    }
    
    Matrix resStrassen = strassen(RandA, RandB, n);
    Matrix resNaive = multiplyNaive(RandA, RandB, n);
    
    // Check if they match
    bool passed = true;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if (resStrassen[i][j] != resNaive[i][j]) {
                passed = false;
            }
        }
    }

    if (passed) {
        cout << "PASS: Strassen's result perfectly matches Naive multiplication!" << endl;
    } else {
        cout << "FAIL: Results do not match." << endl;
    }

    return 0;
}