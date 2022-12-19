#include <iostream>
using namespace std;

#include <time.h>
#include <chrono>


#define BLOCK_SPEED( block_name )\
std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now(); 

#define BLOCK_SPEED_END( block_name )\
std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();\
std::cout << "EXECUTION TIME: " << block_name << " " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;


void merge(int a[], int lb, int mid, int ub)
{
    int b[ub] = {0};
    int k = 0;
    int i = lb, j = mid + 1;

    while (i <= mid && j <= ub)
    {
        if (a[i] <= a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= ub)
    {
        b[k] = a[j];
        j++;
        k++;
    }

    int p = lb;
    for (int i = 0; i < k; i++)
    {
        a[p] = b[i];
        p++;
    }



}

int c = 0;

void mergesort(int arr[], int lb, int ub)
{
    if (lb >= ub)
    {
        return;
    }

    c++;

    int mid = (lb + ub) / 2;
    mergesort(arr, lb, mid);
    mergesort(arr, mid + 1, ub);
    merge(arr, lb, mid, ub);
}

void printarr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " " << endl;
}

int main()
{
    int n;
    cin >> n;

    int *arr = new int[n];

    for ( int i=0; i<n; i++ )
        cin >> arr[i];

    // cout << "The given array is" << endl;
    // printarr(arr, n);

    BLOCK_SPEED("ABIDS CODE")
    mergesort(arr, 0, n - 1);
    BLOCK_SPEED_END("ABIDS CODE END")

    // cout << "The sorted array is" << endl;
    // printarr(arr, n);

    std::cout << "Number of times mergesort is called: " << c << std::endl;
}