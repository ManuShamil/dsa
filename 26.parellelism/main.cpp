#include <iostream>

int main() {
    int n;
    int *arr = new int[n];

    int elemToSearch;

    std::cin >> n;
    for ( int i=0; i<n; i++ )
        std::cin >> arr[i];

    std::cin >> elemToSearch;

    std::cout << "Searching for " << elemToSearch << std::endl;

    return 0;
}