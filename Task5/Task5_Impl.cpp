#include <vector>
std::vector<std::vector<int>> generatePascalTriangle(int n) {
    std::vector<std::vector<int>> triangle;
    
    // Edge case: if n is 0 or negative, return empty triangle
    if (n <= 0) return triangle;

    // The first row is always just {1}
    triangle.push_back({1});

    // Generate subsequent rows
    for (int i = 1; i < n; ++i) {
        std::vector<int> prevRow = triangle[i - 1];
        std::vector<int> currentRow;
        
        currentRow.push_back(1); // First element is always 1

        // Calculate middle elements by adding the two elements above
        // We cast to int just to keep the compiler quiet about the size() type
        for (int j = 1; j < (int)prevRow.size(); ++j) {
            currentRow.push_back(prevRow[j - 1] + prevRow[j]);
        }
        currentRow.push_back(1); // Last element is always 1
        triangle.push_back(currentRow);
    }   
    return triangle;
}