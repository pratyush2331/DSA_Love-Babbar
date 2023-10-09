// 

#include<iostream>
using namespace std;

int main()
{
    const int i = 10;
    const int j = i + 10;     // works fine
    // i++;    // this leads to Compile time error

    return 0;
}