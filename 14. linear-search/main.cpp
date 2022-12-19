//! Program to do linear search on a 1D Array.
#include <iostream>


/**
 * Time complexity: O(n)
 * @brief      Linear search on a 1D array.
 * @param      arr   The arr
 * @param[in]  n     { parameter_description }
 * @param[in]  key   The key
 * @return     { description_of_the_return_value }
 */
int linearSearch( int *arr, int n, int key ) {
    for ( int i=0; i<n; i++ ) {
        if ( arr[i] == key )
            return i;
    }

    return -1;
}

void displayArray( int *arr, int n ) {
    for ( int i=0; i<n; i++ )
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

int main( int argc, char ** argv ) {

    int arr[] = { 9, 15, 65, 24, 10, 65  };
    int n = 6;

    displayArray( arr, n );
    int key = 65;
    int index = linearSearch( arr, n, key );
    if ( index != -1 )
        std::cout << "Found " << key << " at index " << index << std::endl;
    else
        std::cout << "Not found " << key << std::endl;

    return 0;
}