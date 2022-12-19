#include <iostream>

class Node {
public:
    Node root();
    Node() {

    }
};

Node giveNode() {
    std::cout << "Hrlo" << std::endl;
    return Node();
}

int main() {

    Node* root = new Node();
    
    (*(&giveNode))();

    return 0;
}