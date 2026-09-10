#include <cassert>
#include <iostream>

class BinarySearchTree {
private:
    struct Node {
        int value;
        Node* left = nullptr;
        Node* right = nullptr;
        explicit Node(int v) : value(v) {}
    };

    Node* root_ = nullptr;

    static Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->value) node->left = insert(node->left, value);
        else if (value > node->value) node->right = insert(node->right, value);
        return node;
    }

    static bool contains(const Node* node, int value) {
        if (!node) return false;
        if (value == node->value) return true;
        return value < node->value ? contains(node->left, value)
                                   : contains(node->right, value);
    }

    static void inorder(const Node* node) {
        if (!node) return;
        inorder(node->left);
        std::cout << node->value << ' ';
        inorder(node->right);
    }

    static void destroy(Node* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    ~BinarySearchTree() { destroy(root_); }

    void insert(int value) { root_ = insert(root_, value); }
    bool contains(int value) const { return contains(root_, value); }
    void print_inorder() const {
        inorder(root_);
        std::cout << '\n';
    }
};

int main() {
    BinarySearchTree tree;
    for (int value : {50, 30, 70, 20, 40, 60, 80})
        tree.insert(value);

    assert(tree.contains(60));
    assert(tree.contains(20));
    assert(!tree.contains(100));

    tree.print_inorder();
    std::cout << "BST demo passed.\n";
    return 0;
}
