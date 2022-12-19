#include <iostream>
#include <thread>
#include <future>

#include <time.h>
#include <chrono>


#define BLOCK_SPEED( block_name )\
std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); 

#define BLOCK_SPEED_END( block_name )\
std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();\
std::cout << "EXECUTION TIME: " << block_name << " " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

template<typename T>
class BinaryNode {
public:
    T value;
    BinaryNode<T> *left, *right;
    BinaryNode( T val );
    bool operator < (const BinaryNode<T> b) const;
};

template<typename T> 
BinaryNode<T>::BinaryNode( T val )
{
    this->left = this->right = NULL;
    this->value = val;
}

template<typename T>
bool BinaryNode<T>::operator < ( const BinaryNode<T> b ) const 
{
    if ( this->value < b.value ) return true;

    return false;
}

template<typename T>
class BinaryTree 
{
public:
    BinaryNode<T> *rootNode;
    BinaryTree();
    BinaryNode<T>* insert( T value );
    BinaryNode<T>* insert( BinaryNode<T> *newNode,  BinaryNode<T> *insertTo );
    BinaryNode<T>* findMin();
    BinaryNode<T>* findMax();
    void inorder( BinaryNode<T> *node);
    void preorder( BinaryNode<T> *node);
    void postorder( BinaryNode<T> *node ); 
};

template<typename T>
BinaryTree<T>::BinaryTree() 
{
    this->rootNode = NULL;
}

template<typename T> 
BinaryNode<T>* BinaryTree<T>::insert( T value )
{
    BinaryNode<T> *newNode = new BinaryNode<T>( value );
    return this->insert( newNode, this->rootNode );
}

template<typename T> 
BinaryNode<T>* BinaryTree<T>::insert( BinaryNode<T> *newNode, BinaryNode<T> *insertTo )
{
    if ( this->rootNode == NULL )
    {
        this->rootNode = newNode;
        return newNode;
    }

    if ( insertTo == NULL ) insertTo = this->rootNode;

    //std::cout << insertTo->value << " < " << newNode->value << " " << ( *(insertTo) < *(newNode) ) << std::endl;
    
    if ( *newNode < *insertTo )
        if ( insertTo->left == NULL ) 
            insertTo->left = newNode;
        else
            return this->insert( newNode, insertTo->left );
    else
        if ( insertTo->right == NULL )
            insertTo->right = newNode;
        else
            return this->insert( newNode, insertTo->right );

    return newNode;
}

template<typename T> 
void BinaryTree<T>::inorder( BinaryNode<T> *node )
{
    if ( node == NULL )
        return;
  

    this->inorder( node->left );
    std::cout << node->value << " "; 
    this->inorder( node->right );
}

template<typename T>
void BinaryTree<T>::preorder( BinaryNode<T> *node )
{
    if ( node == NULL )
        return;

    std::cout << node->value << " ";
    this->preorder( node->left );
    this->preorder( node->right );
}

template<typename T>
void BinaryTree<T>::postorder( BinaryNode<T>* node)
{
    if ( node == NULL )
        return;

    this->postorder( node->left );
    this->postorder( node->right );
    std::cout << node->value << " ";
}

template<typename T>
BinaryNode<T>* BinaryTree<T>::findMin()
{
    BinaryNode<T> *node = this->rootNode;
    while ( node->left != NULL )
        node = node->left;

    return node;
}

template<typename T>
BinaryNode<T>* BinaryTree<T>::findMax()
{
    BinaryNode<T> *node = this->rootNode;
    while ( node->right != NULL )
        node = node->right;

    return node;
}


int findMinWrapper(BinaryTree<int> *tree) {
    return tree->findMin()->value;
}

int findMaxWrapper(BinaryTree<int> *tree) {
    return tree->findMax()->value;
}

int main( int argc, char **argv )
{

    BinaryTree<int> *tree = new BinaryTree<int>();

    unsigned int range = INT32_MAX;

    int *arr = new int[1000000];
    for ( int i = 0; i < 1000000; i++ )
    {
        arr[i] = rand() % range + 0;
        tree->insert( arr[i] );
    }

    std::cout << "Tree created" << std::endl;


    // int arr[10] = { 88, 99, 44, 35, 44, 101, 66, 50, 25, 66 };

    // for ( int i=0; i<10; i++)
    //     tree->insert( arr[i] );

    BLOCK_SPEED( "MIN AND MAX");
    // std::future<int> minResult = std::async( findMinWrapper, tree );
    // std::future<int> maxResult = std::async( findMaxWrapper, tree );

    std::cout << "FIND MIN: " << tree->findMin()->value << std::endl;
    std::cout << "FIND MAX: " << tree->findMax()->value << std::endl;

    // std::cout << "FIND MIN: " << minResult.get() << std::endl;
    // std::cout << "FIND MAX: " << maxResult.get() << std::endl;

    BLOCK_SPEED_END( "MIN AND MAX" );


    return 0;

    std::cout << "IN ORDER: ";
    tree->inorder( tree->rootNode );
    std::cout << std::endl;

    std::cout << "PRE ORDER: ";
    tree->preorder( tree->rootNode );
    std::cout << std::endl;

    std::cout << "POST ORDER: ";
    tree->postorder( tree->rootNode );
    std::cout << std::endl;

    std::cout << std::endl;
    return 0;
}