#include <iostream>
#include <string>
#include "Task4_Impl.cpp" 

// Helper function to print results cleanly
void printTest(const std::string& testName, int result, int expected) {
    std::cout << testName << ": ";
    if (result == expected) {
        std::cout << "PASS (Index: " << result << ")\n";
    } else {
        std::cout << "FAIL (Got: " << result << ", Expected: " << expected << ")\n";
    }
}
int main() {
    std::cout << "--- Task 4: String Pattern Matching Tests ---\n";
    std::string text = "hello world, welcome to the universe.";

    // Test 1.a: Pattern at the beginning
    printTest("Test 1.a (Beginning)", naiveStringMatch(text, "hello"), 0);

    // Test 1.b: Pattern at the end
    printTest("Test 1.b (End)", naiveStringMatch(text, "universe."), 30);

    // Test 1.c: Pattern not present
    printTest("Test 1.c (Not present)", naiveStringMatch(text, "galaxy"), -1);

    // Test 1.d: Empty pattern
    printTest("Test 1.d (Empty pattern)", naiveStringMatch(text, ""), 0);

    return 0;
}