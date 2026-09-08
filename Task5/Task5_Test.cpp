#include <iostream>
#include <vector>
#include "Task5_Impl.cpp" 

// Helper function to print the entire triangle nicely
void printTriangle(const std::vector<std::vector<int>>& triangle) {
    for (int i = 0; i < (int)triangle.size(); ++i) {
        for (int j = 0; j < (int)triangle[i].size(); ++j) {
            std::cout << triangle[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
// Helper function to check if a specific row matches expected values
bool checkRow(const std::vector<int>& row, const std::vector<int>& expected) {
    if (row.size() != expected.size()) return false;
    for (int i = 0; i < (int)row.size(); ++i) {
        if (row[i] != expected[i]) return false;
    }
    return true;
}
int main() {
    std::cout << "--- Task 5: Pascal's Triangle Tests ---\n\n";

    // Test 2.a: n = 0
    std::cout << "Test 2.a (n = 0):\n";
    std::vector<std::vector<int>> t0 = generatePascalTriangle(0);
    std::cout << "Rows generated: " << t0.size() << " (Expected: 0)\n\n";

    // Test 2.a: n = 1
    std::cout << "Test 2.a (n = 1):\n";
    std::vector<std::vector<int>> t1 = generatePascalTriangle(1);
    printTriangle(t1);
    std::cout << "\n";

    // Test 2.a: n = 5
    std::cout << "Test 2.a (n = 5):\n";
    std::vector<std::vector<int>> t5 = generatePascalTriangle(5);
    printTriangle(t5);
    std::cout << "\n";

    // Test 2.b: Verify row 5 -> {1, 4, 6, 4, 1}
    std::cout << "Test 2.b (Verify Row 5):\n";
    std::vector<int> expectedRow5 = {1, 4, 6, 4, 1};
    
    if (t5.size() >= 5 && checkRow(t5[4], expectedRow5)) {
        std::cout << "PASS: Row 5 matches {1, 4, 6, 4, 1}\n";
    } else {
        std::cout << "FAIL: Row 5 does not match expected values.\n";
    }
    return 0;
}