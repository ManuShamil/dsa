#include <iostream>

void swapInt( int *a, int *b ) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * Time complexity: O(n^2)
 * @brief      Bubble sort on a 1D array.
 * @param      arr   The arr
 * @param[in]  n     { parameter_description }
 */

void bubbleSort( int *arr, int n) {

    for ( int i=0; i<n-1; i++ ) {

        bool flag = false;

        for ( int j=0; j<n-i-1; j++ ) {
            if ( arr[j] >= arr[j+1] ) {
                flag = true;
                swapInt( arr +j, arr +j+1 );
            }
        }

        if ( !flag ) return;
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
    bubbleSort(arr, n);
    displayArray( arr, n );

    return 0;
}