// 

#include<iostream>
using namespace std;

int main() {
    // Pointer to a const variable
    const int* u;
    char const* v;

    // const Pointer
    int x = 1;
    int* const w = &x;

    // const pointer pointing to a const variable
    const int* const z = &x;

    return 0;
}