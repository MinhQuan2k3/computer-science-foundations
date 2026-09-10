#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int linear_search(const std::vector<int>& a, int target) {
    for (std::size_t i = 0; i < a.size(); ++i)
        if (a[i] == target) return static_cast<int>(i);
    return -1;
}

int binary_search_iterative(const std::vector<int>& a, int target) {
    int left = 0;
    int right = static_cast<int>(a.size()) - 1;

    while (left <= right) {
        const int mid = left + (right - left) / 2;
        if (a[mid] == target) return mid;
        if (a[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int binary_search_recursive(const std::vector<int>& a, int target,
                            int left, int right) {
    if (left > right) return -1;

    const int mid = left + (right - left) / 2;
    if (a[mid] == target) return mid;
    if (a[mid] < target)
        return binary_search_recursive(a, target, mid + 1, right);
    return binary_search_recursive(a, target, left, mid - 1);
}

int main() {
    const std::vector<int> values{2, 5, 8, 12, 16, 23, 38, 56};

    assert(linear_search(values, 23) == 5);
    assert(linear_search(values, 99) == -1);

    assert(binary_search_iterative(values, 23) == 5);
    assert(binary_search_iterative(values, 99) == -1);

    assert(binary_search_recursive(values, 23, 0,
                                   static_cast<int>(values.size()) - 1) == 5);

    std::cout << "Searching algorithms passed.\n";
    return 0;
}
