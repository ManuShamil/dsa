#include <iostream>
#include "binarytree.hpp"
#include "stack.hpp"

template<typename T>
class BExpressionTree : public BinaryTree<T>
{
public:
    BinaryNode<T>* insert( T value );
};

template<typename T> 
BinaryNode<T>* BExpressionTree<T>::insert( T value )
{
    //! override here.

    return BinaryTree<T>::insert( value );
}

template<typename T>
class ExpressionTreeStack : public Stack<T>
{
    public:
        Node<T>* push( T value );
        bool isOperator( T c );
        bool isTree( T item );
        void printStack();
};

template<typename T>
bool ExpressionTreeStack<T>::isTree( T item )
{
    if ( auto *item = (BExpressionTree<char>*) item )
        return true;

    return false;
}

template<typename T>
Node<T>* ExpressionTreeStack<T>::push( T value )
{
    //! override here.

    if ( isOperator( value ) )
    {
        Node<T>* a = Stack<T>::pop();
        Node<T>* b = Stack<T>::pop();

        BExpressionTree<char> *tree = new BExpressionTree<char>();
        tree->rootNode = new BinaryNode<char>( *((char*) value) );

        if ( isTree( a->value ) )
            tree->rootNode->left = ( (BExpressionTree<char>*) a->value )->rootNode;
        else
            tree->rootNode->left = new BinaryNode<char>( *((char*) a->value) );

        if ( isTree( b->value ) )
            tree->rootNode->right = ( (BExpressionTree<char>*) b->value )->rootNode;
        else
            tree->rootNode->right = new BinaryNode<char>( *((char*) b->value) );

        

        return Stack<T>::push( tree );
    }

    return Stack<T>::push( value );
}

template<typename T>
bool ExpressionTreeStack<T>::isOperator( T c )
{
    char val = *((char*) c);
    if ( val == '+' || val == '-' || val == '*' || val == '/' ) return true;

    return false;
}

template<typename T>
void ExpressionTreeStack<T>::printStack()
{
    Stack<T>::printStack();
}

int main( int argc, char **argv ) 
{

    char expression[9] = { 'a', 'b', '+', 'c', 'd', 'e', '+', '*', '*' };
    ExpressionTreeStack<void*> *stack = new ExpressionTreeStack<void*>();

    for ( int i=0; i<9; i++ )
    {
        stack->push( &expression[i] );
    }

    BExpressionTree<char> *result = (BExpressionTree<char>*) stack->top;
    result->inorder( result->rootNode );

    return 0;
}