#include <vector>
#include <algorithm>
#include <iostream>

unsigned int findSum(const std::vector<int>& numbers, int sum) {
    unsigned int result{0};
    std::vector<int> partials(numbers.size());
    for(int i=0; i < numbers.size(); ++i) {
        std::cout << "Number: " << numbers[i] << std::endl;
        for(int j=0; j<=i; ++j) {
            partials[j] = partials[j]+ numbers[i];
            std::cout << "Idx: " << j << ", partial: " << partials[j];
            if(partials[j] == sum) {
                std::cout << ", BINGO";
                result++;
            }
            std::cout << std::endl;
        }
    }
    return result;
}

int main() {
    std::vector<int> numbers{1,1,2,3,4,0,-2,2,0,1,-1};
    std::cout << findSum(numbers, 7) << std::endl;
}