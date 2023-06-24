// global variable in C++

#include<iostream>
using namespace std;

void b(int& i) {
    cout << "inside b() : " << i << endl;
}

void a(int& i) {
    cout << "inside a() : " << i << endl;
    b(i);
}

int main() {
    int i = 5;

    cout << "before block : " << i << endl;

    a(i);

    {
        int i = 2;
        cout << "inside block : " << i << endl;
    }

    cout << "after block : " << i << endl;
    
    return 0;
}