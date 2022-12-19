template<typename T>
class Node
{
public:
    T value;
    Node* next;
    Node( T value );
    Node();
};

template<typename T>
Node<T>::Node( T value )
{
    this->value = value;
    this->next = NULL;
}

template<typename T>
Node<T>::Node()
{
    this->next = NULL;
}

