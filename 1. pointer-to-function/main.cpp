#include <stdio.h>
#include <cstring>
#include <iostream>

int return_const( int n ) const {
    return n;
}

int main( ) {

    std::cout << return_const( 5 ) << std::endl;
    return 0;
}