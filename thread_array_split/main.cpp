#include "header.h"
int main() {
    const int N = 20;
    const int M = 4;
    std::vector<int> array(N);
    std::generate(array.begin(), array.end(), []() { return rand() % 10; });
    std::cout << "Generated array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    ArraySum arraySum(array, M);
    arraySum.calculateSum();
    std::cout <<"Total sum is: " << arraySum.getTotalSum();
    return 0;
}