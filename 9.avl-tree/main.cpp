#include <iostream>

#include "binarytree.hpp"


int main( int argc, char **argv )
{
    BinaryTree<int> *tree = new BinaryTree<int>();

    
     unsigned int range = INT32_MAX;

    int *arr = new int[10000];
    for ( int i = 0; i < 10000; i++ )
    {
        arr[i] = rand() % range + 0;
        tree->insert( arr[i] );
    }

    return 0;
}