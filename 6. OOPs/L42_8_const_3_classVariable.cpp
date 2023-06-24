// Initializer List in C++

#include<iostream>
using namespace std;

class Test
{
    const int i;
    public:
    Test(int x):i(x)
    {
        cout << "i value set: " << i << endl;
    }

    void print() {
        cout << this->i << endl;
    }
};

int main()
{
    Test t(10);
    Test s(20);

    t.print();
    s.print();
}