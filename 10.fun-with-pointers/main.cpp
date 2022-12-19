#include <iostream>

class Node {
public:
    char data;
};

int linearSearch( int *arr, int n, int itemToSearchFor ) {
    for ( int i=0; i<n; i++ )
        if ( arr[i] == itemToSearchFor )
            return i;
            
    return -1;
}

int main() {

    int *arr = new int[5];
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;

    int index = linearSearch( arr, 5, 56 );

    std::cout << index << std::endl;

    return 0;
}