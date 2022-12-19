#include <iostream>

class Node {

public:
    int value;
    Node *next;
};

class Stack {
public:
    Node* top;
    Node* push( int val ) {
        Node *newNode = new Node();
        newNode->value = val;

        return this->push( newNode );

    }
    Node* push( Node* newNode ) {
        if ( this->top == NULL ) {
            top = newNode;
            return newNode;
        }

        newNode->next = top;
        top = newNode;

        return newNode;
    }

    Node* pop() {
        Node *popped = top;
        top = top->next;

        popped->next = NULL;
        return popped;
    }

    int size() {
        int count = 0;
        Node* cursor = top;
        while ( cursor != NULL ) {
            count += 1;
            cursor = cursor->next;
        }
        return count;
    }

    void display() {
        Node* cursor = top;
        while ( cursor != NULL ) {
            std::cout << cursor->value;
            if ( cursor->next != NULL ) std::cout << " -> ";
            cursor = cursor->next;
        }
        std::cout << std::endl;
    }
};

void towerOfHanoi( int N, Stack *from, Stack *to, Stack *aux ) {
    if ( N == 0 ) return;

    towerOfHanoi( N-1, from, aux, to );
    Node* popped = from->pop();
    to->push( popped );

    towerOfHanoi( N-1, aux, to, from );
}

int main() {
    Stack *stack1 = new Stack();
    Stack *stack2 = new Stack();
    Stack *stack3 = new Stack();

    stack1->push( 3 );
    stack1->push( 2 );
    stack1->push( 1 );

    towerOfHanoi( 3, stack1, stack2, stack3 );




    stack2->display();
}
