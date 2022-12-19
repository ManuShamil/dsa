#include <iostream>

void swapInt( int *a, int *b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Time complexity: O(n^2)
 * @brief      Insertion sort on a 1D array.
 * @param      arr   The arr
 * @param[in]  n     { parameter_description }
 */

void insertionSort( int *arr, int n) {

    int j;

    for ( int p=1; p<n; p++) {
        int key = arr[p];

        j = p;
        while ( key < arr[j-1] && j > 0) {
            arr[j] = arr[j - 1];
            j--;
        }

        arr[j] = key;
    }
}

void displayArray( int *arr, int n ) {
    for ( int i=0; i<n; i++ ) 
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

int main( int argc, char ** argv ) {

    int arr[] = { 15, 9, 65, 24, 10, 65  };
    int n = 6;

    displayArray( arr, n );
    insertionSort(arr, n);
    displayArray( arr, n );

    return 0;
}