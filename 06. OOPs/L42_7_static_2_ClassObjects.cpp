// Static Class Objects

#include<iostream>
using namespace std;

class Abc
{
    int i;
    public:
    Abc()
    {
        i=0;
        cout << " constructor " << endl;
    }
    ~Abc()
    {
        cout << " destructor " << endl;
    }
};

// without static
// void f()
// {
//     Abc obj;
// }

// with static
void f()
{
    static Abc obj;
}

int main()
{
    int x=0;
    if(x==0)
    {
        f();
    }
    cout << " END " << endl;
}
