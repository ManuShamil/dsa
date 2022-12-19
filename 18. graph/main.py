from typing import List

# graph using adjacency list.
class Graph:

    adjacency_list: map
    visited: map

    def __init__( self ):
        self.adjacency_list = {}
        self.visited = {}

    def addEdge( self, fromEdge, toEdge ):
        
        if fromEdge not in self.adjacency_list:
            self.adjacency_list[ fromEdge ] = []

        self.adjacency_list[fromEdge].append( toEdge )
        
    def DFS( self, fromVertex:int  ):
        
        self.visited[ fromVertex ] = True

        print( fromVertex )

        for vertex in self.adjacency_list.keys():
            if ( vertex not in self.visited.keys() or self.visited[vertex] != True ):
                self.DFS( vertex )

    def BFS( self, fromVertex:int ):

        visited_array = []

        for x in self.adjacency_list.keys():
            visited_array.insert(x, False )
        
        visited_array[ fromVertex ] = True

        queue = []
        queue.insert(0, fromVertex )

        while len(queue) > 0:
            curr_vertex = queue.pop(0)

            print( "Visited " + str(curr_vertex) )

            for adj_vertex in self.adjacency_list[ curr_vertex ]:
                if not visited_array[ adj_vertex ]:
                    visited_array[ adj_vertex ] = True
                    queue.append( adj_vertex )



        print( visited_array )


    def reset_visited( self ):
        self.visited = {}

if __name__ == "__main__":

    graph:Graph = Graph()

    graph.addEdge( 0, 1 )
    graph.addEdge( 1, 0 )
    graph.addEdge( 1, 2 )
    graph.addEdge( 2, 0 )


    graph.reset_visited()
    graph.BFS(2)



