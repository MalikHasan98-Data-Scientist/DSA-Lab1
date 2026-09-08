#include <iostream>
#include <vector>
#include "Task6_Impl.cpp" // Include our implementation file
using namespace std;

// Helper function to print the results nicely
void printModes(string testName, vector<int> modes) {
    cout << testName << ": [";
    for (int i = 0; i < (int)modes.size(); i++) {
        cout << modes[i];
        // Add a comma if it's not the last number
        if (i < (int)modes.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

int main() {
    cout << "--- Task 6: Histogram Analysis (Mode of Array) ---" << endl;

    // Test 3.a: Array with unique mode (2 appears twice, others once)
    vector<int> arr1 = {1, 2, 2, 3, 4};
    printModes("Test 3.a (Unique mode)", findMode(arr1));

    // Test 3.b: Array with multiple modes (1 and 2 both appear twice)
    vector<int> arr2 = {1, 1, 2, 2, 3};
    printModes("Test 3.b (Multiple modes)", findMode(arr2));

    // Test 3.c: Empty array
    vector<int> arr3 = {};
    printModes("Test 3.c (Empty array)", findMode(arr3));

    return 0;
}