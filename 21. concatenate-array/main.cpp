#include <iostream>
#include <cstring>

int* getConcatenation(int* nums, int numsSize, int* returnSize ){
    
    *returnSize = 2 * numsSize;

    nums = (int *) realloc( nums ,  *returnSize * sizeof(int) );

    memcpy( nums + numsSize, nums, numsSize * sizeof(int) );

    //std::copy( nums, nums+numsSize, nums+numsSize );

    // for ( int i=0; i<numsSize; i++ )
    //     nums[ numsSize + i ] = nums[i];

    return nums;
}

void displayArray( int *arr, int n ) {
    for ( int i=0; i<n; i++ )
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

int main() {
    int size = 5;
    int *arr = ( int * ) malloc ( size * (sizeof(int) ));
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;
    arr[4] = 5;


    int returnSize = 5;
    int *out = getConcatenation( arr, size, &returnSize );

    displayArray( out, returnSize);
}