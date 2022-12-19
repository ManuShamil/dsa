/*
Try to create an array of N elements as input which consists of Positive, Negative
numbers and also the duplicate values. Perform any sorting procedure to get
output as two sorted array one with positive numbers and one with negative
numbers and print the number of comparisons made for each sorted array and aslo
the say count for the each the duplicate values.
Exapmle : input[15]= { 10,4,-3,-1,0,4,3,-15,-8,4,-1,9,3,1,7}
Output1[15]={-1,-1,-3,-8,-15} and print Number of Comparisons
Output2[15]={0,1,3,3,4,4,4,7,9,10} and print Number of Comparisons
-1 has been present twice
+ 3 has been present twice
+ 4 has been present thrice
*/

#include <iostream>

/**
 * @brief      Sort Array
 * @param      arr   The arr
 * @param[in]  n     { parameter_description }
 * @param      comp  The comp
 */
void sortArray( int *arr, int n, int *comp ) {
    for ( int i=0; i<n-1; i++ ) {
        for ( int j=0; j<n-i-1; j++ ) {
            if ( arr[j] > arr[j+1] ) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            *comp += 1;
        }
    }
}

/**
 * @brief      Returns all positive integers in an array.
 * @param   arr   The arr
 * @param   n     The n
*/
int* getAllPositiveIntegers( int *arr, int n, int *count ) {
    int *positiveIntegers = new int[n];
    int j = 0;
    for ( int i=0; i<n; i++ ) {
        if ( arr[i] >= 0 ) {
            positiveIntegers[j] = arr[i];
            j++;
        }
    }

    *count = j;

    return positiveIntegers;
}

/**
 * @brief      Returns all negative integers in an array.
 * @param   arr   The arr
 * @param   n     The n
*/
int* getAllNegativeIntegers( int *arr, int n, int *count ) {
    int *negativeIntegers = new int[n];
    int j = 0;
    for ( int i=0; i<n; i++ ) {
        if ( arr[i] < 0 ) {
            negativeIntegers[j] = arr[i];
            j++;
        }
    }

    *count = j;

    return negativeIntegers;
}

/**
 * @brief      Display count of each element in an array.
 * @param      arr   The arr
 * @param[in]  n     { parameter_description }
 */
void displayCountOfEachElement( int *arr, int n ) {
    int count = 1;
    for ( int i=0; i<n; i++ ) {
        if ( arr[i] == arr[i+1] ) {
            count++;
        } else {
            if ( count > 1)
                std::cout << arr[i] << " has been present " << count << " times" << std::endl;
            count = 1;
        }
    }
}

int main() {

    int *arr = new int[100];

    int n;

    std::cin >> n;

    for ( int i=0; i<n; i++ )
        std::cin >> arr[i];

    int positiveIntegersCount = 0;
    int negativeIntegersCount = 0;

    int *positiveIntegers = getAllPositiveIntegers( arr, n, &positiveIntegersCount );
    int *negativeIntegers = getAllNegativeIntegers( arr, n, &negativeIntegersCount );

    int positiveComparisons = 0;
    sortArray( positiveIntegers, positiveIntegersCount, &positiveComparisons );

    std::cout << "Positive Integers: " << std::endl;
    for ( int i=0; i<n; i++ ) {
        if ( positiveIntegers[i] >= 0 )
            std::cout << positiveIntegers[i] << " ";
    }

    std::cout << "Number of comparisons: " << positiveComparisons << std::endl;

    std::cout << "Negative Integers: " << std::endl;
    for ( int i=0; i<negativeIntegersCount; i++ ) {
        if ( negativeIntegers[i] < 0 )
            std::cout << negativeIntegers[i] << " ";
    }

    int negativeComparisons = 0;
    sortArray( negativeIntegers, negativeIntegersCount, &negativeComparisons );

    std::cout << "Number of comparisons: " << negativeComparisons << std::endl;

    displayCountOfEachElement( positiveIntegers, positiveIntegersCount );
    displayCountOfEachElement( negativeIntegers, negativeIntegersCount );




    return 0;
}