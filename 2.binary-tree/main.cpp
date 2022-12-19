#include <iostream>

template<class T> 
class BinaryNode {
    public:
        T data;
        BinaryNode<T> *left;
        BinaryNode<T> *right;
        BinaryNode(T data) {
            this->data = data;
            this->left = nullptr;
            this->right = nullptr;
        }
};


template<class T>
class BinaryTree {
    public:
        BinaryNode<T> *root;
        BinaryTree() {
            this->root = nullptr;
        }
        void insert(T data) {
            BinaryNode<T> *node = new BinaryNode<T>(data);
            if (this->root == nullptr) {
                this->root = node;
            } else {
                BinaryNode<T> *current = this->root;
                while (true) {
                    if (data < current->data) {
                        if (current->left == nullptr) {
                            current->left = node;
                            break;
                        } else {
                            current = current->left;
                        }
                    } else if (data > current->data) {
                        if (current->right == nullptr) {
                            current->right = node;
                            break;
                        } else {
                            current = current->right;
                        }
                    } else {
                        break;
                    }
                }
            }
        }
        void print() {
            this->print(this->root);
        }
        void print(BinaryNode<T> *node) {
            if (node != nullptr) {
                this->print(node->left);
                std::cout << node->data << std::endl;
                this->print(node->right);
            }
        }
};

int main( int argc, char **argv) {



    return 0;
}