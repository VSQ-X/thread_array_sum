#include <iostream>
#include <vector>
#include <thread>
#include <numeric>
#include <chrono>
#include <algorithm>
class ArraySum {
public:
    ArraySum(const std::vector<int>& array, int num_parts);
    void calculateSum();
    int getTotalSum() const;
    void calculatePartSum(int start, int end, int part_index);
private:
    const std::vector<int>& array;
    int num_parts;
    std::vector<int> part_sums;
    int total_sum = 0;
};
