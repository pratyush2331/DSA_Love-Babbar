// Static Variables inside functions

#include<iostream>
using namespace std;

// without static keyword
// void counter()
// {
//     int count=0;
//     cout << count++ << " ";
// }

// with static keyword
void counter()
{
    static int count=0;
    cout << count++ << " ";
}

int main()
{
    for(int i=0;i<5;i++)
    {
        counter();
    }
}