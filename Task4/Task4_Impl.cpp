#include <string>

// Naive string pattern matching algorithm
int naiveStringMatch(const std::string& text, const std::string& pattern) {
    int n = text.length();
    int m = pattern.length();
    
    // Edge case: empty pattern is found at index 0
    if (m == 0) return 0; 
    
    // If pattern is longer than text, it can't be found
    if (n < m) return -1;

    for (int i = 0; i <= n - m; ++i) {
        int j;
        // Check for pattern match at current index 'i'
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j]) {
                break;
            }
        }
        // If the inner loop completed, we found a match
        if (j == m) {
            return i; 
        }
    }   
    return -1;
}