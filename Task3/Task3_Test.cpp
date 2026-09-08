#include <iostream>
#include <vector>
#include "Task3_Impl.cpp" 

// Helper function to print the vector of indices nicely
void printResult(const std::string& testName, const std::vector<int>& indices) {
    std::cout << testName << ": [";
    for (int i = 0; i < indices.size(); ++i) {
        std::cout << indices[i];
        if (i < indices.size() - 1) std::cout << ", ";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << "--- Task 3: Find All Indices Tests ---\n";

    // Test 3.a: Multiple occurrences
    std::vector<int> arr1 = {1, 2, 3, 2, 4, 2, 5};
    std::vector<int> res1 = findAllIndices(arr1, 2);
    printResult("Test 3.a (Multiple occurrences, key=2)", res1); 

    // Test 3.b: Key not present
    std::vector<int> res2 = findAllIndices(arr1, 9);
    printResult("Test 3.b (Key not present, key=9)", res2); 

    // Test 3.c: Empty array
    std::vector<int> arr3 = {};
    std::vector<int> res3 = findAllIndices(arr3, 1);
    printResult("Test 3.c (Empty array)", res3); 

    return 0;
}