#include <cassert>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
private:
    std::vector<T> data_;

public:
    void push(const T& value) { data_.push_back(value); }

    void pop() {
        if (empty()) throw std::out_of_range("pop from empty stack");
        data_.pop_back();
    }

    const T& top() const {
        if (empty()) throw std::out_of_range("top of empty stack");
        return data_.back();
    }

    bool empty() const { return data_.empty(); }
    std::size_t size() const { return data_.size(); }
};

int main() {
    Stack<int> stack;
    assert(stack.empty());

    stack.push(10);
    stack.push(20);
    stack.push(30);

    assert(stack.top() == 30);
    assert(stack.size() == 3);

    stack.pop();
    assert(stack.top() == 20);

    std::cout << "Stack demo passed.\n";
    return 0;
}
