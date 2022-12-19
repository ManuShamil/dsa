#include <iostream>

#include <time.h>
#include <chrono>


#define BLOCK_SPEED( block_name )\
std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); 

#define BLOCK_SPEED_END( block_name )\
std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();\
std::cout << "EXECUTION TIME: " << block_name << " " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;


void displayArray( int *arr, int n ) {
    for ( int i=0; i<n; i++ )
        std::cout << arr[i] << " ";

    std::cout << std::endl;
}

class MergeSort
{
private:
    void sortArray( int *arr, int n );
    int* mergeArray( int *a, int aN, int *b, int bN );

public:
    int *array;
    int size;
    MergeSort( int *arr, int n );
    void sort();
};


MergeSort::MergeSort( int *arr, int n) {
    this->array = arr;
    this->size = n;
}

int* MergeSort::mergeArray( int *a, int aN, int *b, int bN ) {

    int *newArr = new int[aN + bN];

    int aCtr = 0, bCtr = 0, newArrCtr = 0;

    while ( aCtr < aN && bCtr < bN )
        if ( a[aCtr] < b[bCtr] )
            newArr[newArrCtr++] = a[aCtr++];
        else
            newArr[newArrCtr++] = b[bCtr++];

    
    while ( aCtr < aN )
        newArr[newArrCtr++] = a[aCtr++];

    while ( bCtr < bN )
        newArr[newArrCtr++] = b[bCtr++];

    return newArr;
}

void MergeSort::sortArray( int arr[], int n ) {

    int mid = n/2;
    int remainder = n % 2;
    
    if ( mid <= 0 ) return;

    int firstHalfSize = mid;
    int secondHalfSize = mid + remainder;

    int *firstHalf = arr;
    int *secondHalf = arr + mid;

    this->sortArray( firstHalf, firstHalfSize );
    this->sortArray( secondHalf, secondHalfSize );


    int *mergedArr = this->mergeArray( firstHalf, firstHalfSize, secondHalf, secondHalfSize );

    for ( int i=0; i < firstHalfSize+secondHalfSize; i++)
        arr[i] = mergedArr[i];

}


void MergeSort::sort() {
    this->sortArray( this->array, this->size);
}

int main() {

    int *arr = new int[100];

    int n;
    std::cin >> n;

    for ( int i=0; i<n; i++ )
        std::cin >> arr[i];


    MergeSort sortA( arr, n );
BLOCK_SPEED("MY CODE")
    sortA.sort();
BLOCK_SPEED_END("MY CODE END")

    displayArray( arr, n );

    return 0;
}