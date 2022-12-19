#include <iostream>

int main() {
    
    int a;

    __asm__ ( "mov $20, %%eax;"
            "movl $10, %%ebx;"
            "subl %%ebx, %%eax ":"=a"(a));

    std::cout << a;

    return 0;
}