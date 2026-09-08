#include <vector>
using namespace std;

// Function to find the mode (most frequent element) in an array
vector<int> findMode(vector<int> arr) {
    vector<int> modes;
    int size = arr.size();

    // Test 3.c: If the array is empty, return an empty list
    if (size == 0) {
        return modes;
    }

    int maxFreq = 0;

    // Step 1: Find the highest frequency of any number
    for (int i = 0; i < size; i++) {
        int count = 0;
        // Count how many times arr[i] appears in the whole array
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        // Update maxFreq if we found a higher count
        if (count > maxFreq) {
            maxFreq = count;
        }
    }

    // Step 2: Find all numbers that have this highest frequency
    for (int i = 0; i < size; i++) {
        int count = 0;
        for (int j = 0; j < size; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }

        // If this number's count matches the max frequency
        if (count == maxFreq) {
            // Check if we already added it to our list (to avoid duplicates)
            bool alreadyAdded = false;
            for (int k = 0; k < (int)modes.size(); k++) {
                if (modes[k] == arr[i]) {
                    alreadyAdded = true;
                    break;
                }
            }

            // If it's not in the list yet, add it!
            if (!alreadyAdded) {
                modes.push_back(arr[i]);
            }
        }
    }

    return modes;
}