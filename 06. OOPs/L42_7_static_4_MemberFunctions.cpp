// Static Member Functions

#include<iostream>
using namespace std;

class X
{
    public:
    static void f()
    {
        // statement
    }
};

int main()
{
    X::f();   // calling member function directly with class name
}