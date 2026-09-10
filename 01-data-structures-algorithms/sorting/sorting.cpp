#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

void bubble_sort(std::vector<int>& a) {
    for (std::size_t i = 0; i < a.size(); ++i) {
        bool swapped = false;
        for (std::size_t j = 0; j + 1 < a.size() - i; ++j) {
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void selection_sort(std::vector<int>& a) {
    for (std::size_t i = 0; i < a.size(); ++i) {
        std::size_t min_index = i;
        for (std::size_t j = i + 1; j < a.size(); ++j)
            if (a[j] < a[min_index]) min_index = j;
        std::swap(a[i], a[min_index]);
    }
}

void insertion_sort(std::vector<int>& a) {
    for (std::size_t i = 1; i < a.size(); ++i) {
        const int key = a[i];
        std::size_t j = i;
        while (j > 0 && a[j - 1] > key) {
            a[j] = a[j - 1];
            --j;
        }
        a[j] = key;
    }
}

void merge_sort_impl(std::vector<int>& a, std::vector<int>& temp,
                     std::size_t left, std::size_t right) {
    if (right - left <= 1) return;
    const std::size_t mid = left + (right - left) / 2;
    merge_sort_impl(a, temp, left, mid);
    merge_sort_impl(a, temp, mid, right);

    std::size_t i = left, j = mid, k = left;
    while (i < mid && j < right)
        temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];
    while (i < mid) temp[k++] = a[i++];
    while (j < right) temp[k++] = a[j++];

    for (std::size_t p = left; p < right; ++p) a[p] = temp[p];
}

void merge_sort(std::vector<int>& a) {
    std::vector<int> temp(a.size());
    merge_sort_impl(a, temp, 0, a.size());
}

void quick_sort(std::vector<int>& a, int left, int right) {
    if (left >= right) return;

    int i = left;
    int j = right;
    const int pivot = a[left + (right - left) / 2];

    while (i <= j) {
        while (a[i] < pivot) ++i;
        while (a[j] > pivot) --j;
        if (i <= j) {
            std::swap(a[i], a[j]);
            ++i;
            --j;
        }
    }

    if (left < j) quick_sort(a, left, j);
    if (i < right) quick_sort(a, i, right);
}

void quick_sort(std::vector<int>& a) {
    if (!a.empty())
        quick_sort(a, 0, static_cast<int>(a.size()) - 1);
}

bool is_sorted(const std::vector<int>& a) {
    return std::is_sorted(a.begin(), a.end());
}

int main() {
    const std::vector<int> input{64, 34, 25, 12, 22, 11, 90, 11};

    std::vector<int> a = input;
    bubble_sort(a);
    assert(is_sorted(a));

    a = input;
    selection_sort(a);
    assert(is_sorted(a));

    a = input;
    insertion_sort(a);
    assert(is_sorted(a));

    a = input;
    merge_sort(a);
    assert(is_sorted(a));

    a = input;
    quick_sort(a);
    assert(is_sorted(a));

    std::cout << "Sorting algorithms passed.\n";
    return 0;
}
