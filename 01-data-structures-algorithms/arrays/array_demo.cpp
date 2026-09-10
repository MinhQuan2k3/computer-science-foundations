#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> values{10, 20, 30, 40};

    assert(values.size() == 4);
    assert(values[0] == 10);
    assert(values[2] == 30);

    values.push_back(50);
    assert(values.back() == 50);

    values.erase(values.begin() + 1);
    assert(values.size() == 4);
    assert(values[1] == 30);

    std::cout << "Array demo passed.\n";
    return 0;
}
