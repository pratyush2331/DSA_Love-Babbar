// C++/C program to check endian-ness

#include <bits/stdc++.h>
using namespace std;

/*
In this example:
Little-endian system: x = 0x01020304 will be stored in memory as 04 03 02 01. c[0] will access the first byte, which is 04.
Big-endian system: x = 0x01020304 will be stored in memory as 01 02 03 04. c[0] will access the first byte, which is 01.
*/

int main() {
    uint32_t x = 0x01020304;
    char *c = (char*) &x;

    if (*c == 1) {
        printf("Big-endian\n");
    } else {
        printf("Little-endian\n");
    }

    return 0;
}
