//! Make me a program to do heap sort on binary tree
//! I will use the heap sort algorithm to sort the binary tree

#include <iostream>

void swapInt( int *a, int *b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify( int *arr, int n, int i ) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if ( left < n && arr[left] > arr[largest] )
        largest = left;

    if ( right < n && arr[right] > arr[largest] )
        largest = right;

    if ( largest != i ) {
        swapInt( arr +i, arr +largest );
        heapify( arr, n, largest );
    }
}

/**
 * Time complexity: O(n log n)
 * @brief      Heap sort on a 1D array.
 * @param      arr   The arr
 * @param[in]  n     { parameter_description }
 */
void heapSort( int *arr, int n ) {
    for ( int i=n/2 - 1; i>=0; i-- )
        heapify( arr, n, i );

    for ( int i=n-1; i>=0; i-- ) {
        swapInt( arr, arr +i );
        heapify( arr, i, 0 );
    }
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
    heapSort(arr, n);
    displayArray( arr, n );

    return 0;
}

