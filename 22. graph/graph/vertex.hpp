template<typename T>
class Vertex {

    const static int MAX_SIZE_ADJACENCY_LIST = 50;


public:
    Vertex **adjacencyList;
    T* value;
    unsigned int countAdjacentNodes = 0;

    Vertex( T value );
    bool visited = false;
    void addAdjacentNode( Vertex<T> *node );
};

template<typename T>
Vertex<T>::Vertex( T value ) {
    this->value = &value;
    this->adjacencyList = ( Vertex** ) malloc ( MAX_SIZE_ADJACENCY_LIST * sizeof( Vertex * ) );
}

template<typename T>
void Vertex<T>::addAdjacentNode( Vertex<T> *node ) {
    this->adjacencyList[ countAdjacentNodes++ ] = node;
}