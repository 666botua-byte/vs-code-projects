#include <iostream>

int main() {
    int number;
    std::cin >> number;
    std::string result = "x";
    
    // Write your code below
    int score = number;
    result = (score > 0) ? "positive!" : (score < 0) ? "negative" : "zero";
    
    std::cout << "The number is " << result << std::endl;
    return 0;
}