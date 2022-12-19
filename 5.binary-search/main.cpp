/*
* Program to do binary search on a 1D Array
*/

#include <iostream>

/**
 * Time complexity: O(log n)
 * @brief      Binary search on a 1D array.
 * @param      arr   The arr
 * @param[in]  n     { parameter_description }
 * @param[in]  key   The key
 * @return     { description_of_the_return_value }
 */
int binarySearch( int *arr, int n, int key ) {
    int low = 0;
    int high = n - 1;
    int mid;

    while ( low <= high ) {
        mid = ( low + high ) / 2;

        if ( arr[mid] == key )
            return mid;
        else if ( arr[mid] < key )
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

void displayArray( int *arr, int n ) {
    for ( int i=0; i<n; i++ )
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

int main( int argc, char ** argv ) {

    int arr[] = { 9, 15, 24, 65, 65, 100  };
    int n = 6;

    displayArray( arr, n );
    int key = 65;
    int index = binarySearch( arr, n, key );
    if ( index != -1 )
        std::cout << "Found " << key << " at index " << index << std::endl;
    else
        std::cout << "Not found " << key << std::endl;

    return 0;
}
