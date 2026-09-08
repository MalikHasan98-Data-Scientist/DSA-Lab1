#include <vector>

std::vector<int> findAllIndices(const std::vector<int>& arr, int key) {
    std::vector<int> indices;
    
    // Loop through the array
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) {
            indices.push_back(i); // Store the index if it matches the key
        }
    }    
    return indices;
}