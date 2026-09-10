#include <cassert>
#include <cstddef>
#include <iostream>
#include <queue>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::queue<T> data_;

public:
    void enqueue(const T& value) { data_.push(value); }

    void dequeue() {
        if (empty()) throw std::out_of_range("dequeue from empty queue");
        data_.pop();
    }

    const T& front() const {
        if (empty()) throw std::out_of_range("front of empty queue");
        return data_.front();
    }

    bool empty() const { return data_.empty(); }
    std::size_t size() const { return data_.size(); }
};

int main() {
    Queue<int> queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    assert(queue.front() == 10);
    queue.dequeue();
    assert(queue.front() == 20);
    assert(queue.size() == 2);

    std::cout << "Queue demo passed.\n";
    return 0;
}
