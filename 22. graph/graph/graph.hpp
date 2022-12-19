/**
 * Graph
*/

#include <iostream>
#include "vertex.hpp"
#include "../stack.hpp"

template<typename T>
class Graph {
public:
    Graph();
    void addAdjacentNode( Vertex<T> *from, Vertex<T> *to );
    void DFS( Vertex<T> *from );
    void BFS( Vertex<T> *from, Stack<Vertex<T>> *stack );
};

template<typename T>
Graph<T>::Graph() {
    
}

template<typename T>
void Graph<T>::DFS( Vertex<T> *from ) {
    
    from->visited = true;

    std::cout << *(from->value) << " ";

    for ( int i=0; i<from->countAdjacentNodes; i++ ) {

        Vertex<T> *neighbour = from->adjacencyList[i];
        if ( !neighbour->visited)
            DFS( neighbour );
    }

}

template<typename T>
void Graph<T>::BFS( Vertex<T> *from, Stack<Vertex<T>> *stack ) {
    
    from->visited = true;


}

template<typename T>
void Graph<T>::addAdjacentNode( Vertex<T> *from, Vertex<T> *to ) {
    from->addAdjacentNode( to );
}

/**
 * Directed Graph
*/

template<typename T>
class DirectedGraph : public Graph<T> {
public:
    void addAdjacentNode( Vertex<T> *from, Vertex<T> *to );
};

template<typename T>
void DirectedGraph<T>::addAdjacentNode( Vertex<T> *from, Vertex<T> *to ) {
    Graph<T>::addAdjacentNode( from, to );
}

/**
 * Undirected Graph
*/

template<typename T>
class UndirectedGraph : public Graph<T> {
public:
    void addAdjacentNode( Vertex<T> *from, Vertex<T> *to );
};

template<typename T>
void UndirectedGraph<T>::addAdjacentNode( Vertex<T> *from, Vertex<T> *to ) {
    from->addAdjacentNode( to );
    to->addAdjacentNode( from );
}
