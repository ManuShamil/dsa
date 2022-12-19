/*
2. Perform Binary Search for the given input
A[14]={11,22,33,44,55,66,77,88,99,111,222,333,444}
And try to print the position of the number present in the upper half starting from 1
to n N is the middle element.
After middle element again the position should start from 1 to n. Here N is the last
element.
Example mid = (0+14)/2 ==7 middle element is 88
Numbers 33 present in the third position
88 is present in the ninth positon
99 is present in first position
333 is present in fourth position
*/

#include <iostream>

/**
 * @brief      Binary search on a 1D array.
 * @param      arr   The arr
 * @param[in]  n
 * @param[in]  key   The key
 * @return     index of the item.
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

void findInSplicedArray( int *arr, int n, int elementToSearchFor ) {

    int index = binarySearch( arr, n, elementToSearchFor );

    if ( index == -1 )
    {
        std::cout << "Element " << elementToSearchFor << " not found!" << std::endl;
        return;
    } 

    std::cout << "Element " << elementToSearchFor << " found at position: " << index + 1 << std::endl;
}

int main( int argc, char ** argv ) {

    int arr[] = { 1,22,33,44,55,66,77,88,99,111,222,333,444 };
    int n = 13;

    //displayArray( arr, n );
    int key = 33;
    int index = binarySearch( arr, n, key );

    int midOffset = (n/2 + (n%2)) + 1;

    findInSplicedArray( arr, midOffset, 33);
    findInSplicedArray( arr, midOffset, 88);

    findInSplicedArray( arr + midOffset, n/2, 99);
    findInSplicedArray( arr + midOffset, n/2, 333);
    

    return 0;
}
