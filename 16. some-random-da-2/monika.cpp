#include <iostream>
using namespace std;
int search(int x[], int s, int e, int k)
{
    if (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (x[mid] == k)
            return mid;
        if (x[mid] > k)
            return search(x, s, mid - 1, k);
        else
            return search(x, mid + 1, e, k);
    }
    return -1;
}
int main()
{
    cout << "Enter the no. of elements in array: ";
    int n;
    cin >> n;
    int *a = new int[n];
    cout << "Enter the values:-\n";
    for (int q = 0; q < n; q++)
        cin >> a[q];
    cout << "Enter element to sear1ch: ";
    int k;
    cin >> k;
    int mid = 0 + (n - 1 - 0) / 2;
    int g = search(a, 0, n - 1, k);
    if (g == -1)
        cout << "Not found\n\n";
    else
        cout << "Found at " << (g % (mid + 1)) + 1 << endl
             << endl;
    return 0;
}