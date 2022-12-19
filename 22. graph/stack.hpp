#include "node.hpp"

template<typename T>
class Stack
{
public:
    Node<T>* top;
    Stack();
    Node<T>* push( T value );
    Node<T>* push( Node<T>* newNode );
    Node<T>* pop();
    bool isInStack( Node<T>* node );
    bool isEmpty();
    void printStack();
};

template<typename T>
Stack<T>::Stack()
{
    this->top = NULL;
}

template<typename T>
Node<T>* Stack<T>::push( T value )
{
    Node<T>* newNode = new Node<T>( value );
    return this->push( newNode );
}

template<typename T>
Node<T>* Stack<T>::push( Node<T>* newNode )
{
    if ( this->top == NULL )
    {
        this->top = newNode;
        return newNode;
    }

    newNode->next = this->top;
    this->top = newNode;
    return newNode;
}

template<typename T>
Node<T>* Stack<T>::pop()
{
    if ( this->top == NULL ) return NULL;

    Node<T>* temp = this->top;
    this->top = this->top->next;
    return temp;
}

template<typename T>
bool Stack<T>::isEmpty()
{
    if ( this->top == NULL ) return true;

    return false;
}

template<typename T>
bool Stack<T>::isInStack( Node<T>* node )
{
    Node<T>* temp = this->top;
    while ( temp != NULL )
    {
        if ( node == temp ) return true;
        temp = temp->next;
    }

    return false;
}

template<typename T>
void Stack<T>::printStack()
{
    Node<T>* temp = this->top;
    while ( temp != NULL )
    {
        std::cout << temp->value << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}