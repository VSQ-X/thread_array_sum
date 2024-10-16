#include "header.h"
int main() {
    const int N = 200000;
    const int M = 1;
    std::vector<int> array(N);
    std::generate(array.begin(), array.end(), []() { return rand() % 10; });
    std::cout << "Generated array: ";
    for (int num : array) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    // Подсчет суммы с использованием нескольких потоков
    ArraySum arraySum(array, M);
    auto start = std::chrono::high_resolution_clock::now();
    arraySum.calculateSum();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Sum with threads: " << arraySum.getTotalSum() << std::endl;
    std::cout << "Time with threads: " << duration.count() << " seconds" << std::endl;

    // Подсчет суммы в основном потоке
    start = std::chrono::high_resolution_clock::now();
    int single_thread_sum = std::accumulate(array.begin(), array.end(), 0);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Sum in main thread: " << single_thread_sum << std::endl;
    std::cout << "Time in main thread: " << duration.count() << " seconds" << std::endl;
    return 0;
}