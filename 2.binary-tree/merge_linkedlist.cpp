//! merge two sorted linked list.

#include <iostream>

class Node {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data = data;
            this->next = nullptr;
        }
};

class LinkedList {
    public:
        Node *head;
        LinkedList() {
            this->head = nullptr;
        }
        void insert(int data) {
            Node *node = new Node(data);
            if (this->head == nullptr) {
                this->head = node;
            } else {
                Node *current = this->head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = node;
            }
        }
        void print() {
            Node *current = this->head;
            while (current != nullptr) {
                std::cout << current->data << std::endl;
                current = current->next;
            }
        }
        void merge(LinkedList *list) {
            Node *current1 = this->head;
            Node *current2 = list->head;
            Node *head = nullptr;
            Node *current = nullptr;
            while (current1 != nullptr && current2 != nullptr) {
                if (current1->data < current2->data) {
                    if (head == nullptr) {
                        head = current1;
                        current = current1;
                    } else {
                        current->next = current1;
                        current = current->next;
                    }
                    current1 = current1->next;
                } else {
                    if (head == nullptr) {
                        head = current2;
                        current = current2;
                    } else {
                        current->next = current2;
                        current = current->next;
                    }
                    current2 = current2->next;
                }
            }
            while (current1 != nullptr) {
                current->next = current1;
                current = current->next;
                current1 = current1->next;
            }
            while (current2 != nullptr) {
                current->next = current2;
                current = current->next;
                current2 = current2->next;
            }
            this->head = head;
        }
};

int main() {

    LinkedList *l1 = new LinkedList();
    l1->insert(1);
    l1->insert(2);

    LinkedList *l2 = new LinkedList();
    l2->insert(3);
    l2->insert(5);

    std::cout << "OUTPUT: " << std::endl;

    l1->merge(l2);
    l1->print();
    
}