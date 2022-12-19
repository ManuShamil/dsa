#include <iostream>

#include "graph/graph.hpp"

int main() {

    UndirectedGraph<int> *myGraph = new UndirectedGraph<int>();

    Vertex<int> a(10);
    Vertex<int> b(15);

    Vertex<int> c(30);
    Vertex<int> d(45);

    Vertex<int> e(55);
    Vertex<int> f(90);

    myGraph->addAdjacentNode( &a, &b );
    myGraph->addAdjacentNode( &a, &c );
    myGraph->addAdjacentNode( &a, &d );

    myGraph->addAdjacentNode( &b, &c );

    myGraph->addAdjacentNode( &c, &d );

    myGraph->addAdjacentNode( &c, &e );
    myGraph->addAdjacentNode( &e, &f );

    myGraph->DFS( &a );

    std::cout << *(a.adjacencyList[0]->value) << std::endl;

    return 0;
}