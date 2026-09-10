#include <cassert>
#include <cstddef>
#include <iostream>

class SinglyLinkedList {
private:
    struct Node {
        int value;
        Node* next;
        Node(int v, Node* n = nullptr) : value(v), next(n) {}
    };

    Node* head_ = nullptr;
    std::size_t size_ = 0;

public:
    ~SinglyLinkedList() {
        clear();
    }

    void push_front(int value) {
        head_ = new Node(value, head_);
        ++size_;
    }

    void push_back(int value) {
        Node* node = new Node(value);
        if (!head_) {
            head_ = node;
        } else {
            Node* current = head_;
            while (current->next) current = current->next;
            current->next = node;
        }
        ++size_;
    }

    bool remove(int value) {
        Node* current = head_;
        Node* previous = nullptr;

        while (current) {
            if (current->value == value) {
                if (previous) previous->next = current->next;
                else head_ = current->next;
                delete current;
                --size_;
                return true;
            }
            previous = current;
            current = current->next;
        }
        return false;
    }

    bool contains(int value) const {
        for (Node* current = head_; current; current = current->next)
            if (current->value == value) return true;
        return false;
    }

    std::size_t size() const { return size_; }

    void clear() {
        while (head_) {
            Node* next = head_->next;
            delete head_;
            head_ = next;
        }
        size_ = 0;
    }

    void print() const {
        for (Node* current = head_; current; current = current->next)
            std::cout << current->value << ' ';
        std::cout << '\n';
    }
};

int main() {
    SinglyLinkedList list;
    list.push_front(20);
    list.push_front(10);
    list.push_back(30);

    assert(list.size() == 3);
    assert(list.contains(20));
    assert(list.remove(20));
    assert(!list.contains(20));
    assert(list.size() == 2);

    list.print();
    std::cout << "Linked list demo passed.\n";
    return 0;
}
