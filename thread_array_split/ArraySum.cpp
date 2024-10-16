#include "header.h"
ArraySum::ArraySum(const std::vector<int>& array, int num_parts)
    : array(array), num_parts(num_parts), part_sums(num_parts, 0) {}
void ArraySum::calculateSum() {
    std::vector<std::thread> threads;
    int part_size = array.size() / num_parts;

    for (int i = 0; i < num_parts; ++i) {
        int start = i * part_size;
        int end = (i == num_parts - 1) ? array.size() : start + part_size;
        threads.emplace_back(&ArraySum::calculatePartSum, this, start, end, i);
    }

    std::for_each(threads.begin(), threads.end(), [](std::thread& t)
        { t.join(); });
    total_sum = std::accumulate(part_sums.begin(), part_sums.end(), 0);
}
int ArraySum::getTotalSum() const{
    return total_sum;
}
void ArraySum::calculatePartSum(int start, int end, int part_index) {
    int sum = 0;
    for (int i = start; i < end; ++i) {
        std::cout << array[i]<<" ";
        sum += array[i];
    }
    std::cout << "\n";
    part_sums[part_index] = sum;
}