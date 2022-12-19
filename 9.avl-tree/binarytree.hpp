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