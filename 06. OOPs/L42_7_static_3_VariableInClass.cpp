// 

#include<iostream>
using namespace std;

class X
{
    public:
    static int i;
    X()
    {
        // construtor
    };
};

int X :: i = 1;

int main() {
    X obj;
    obj.i = 2;
    cout << obj.i++ << endl;   // prints value of i

    X obj2;
    cout << obj2.i << endl;
}