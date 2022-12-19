#include <iostream>
#include <list>

class Graph {
public:
    std::list<int> *adjacencyList;

    Graph( int size ) {
        this->adjacencyList = ( std::list<int>* ) malloc ( size * sizeof( std::list<int> ) );
    }

    void addEdge( int src, int dest ) {
        adjacencyList[src].push_back( dest );
    }

    
};

int main() {

    Graph myGraph( 10 );

    return 0;
}