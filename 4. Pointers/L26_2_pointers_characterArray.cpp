// pointers & character arrays

#include<iostream>
using namespace std;

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    char ch[6] = "abcde";   // bcz, ch[5] = '\0' (indexing from 0)

    cout << "phase - 1" << endl;
    cout << arr << endl;
    // attention here
    cout << ch << endl;
    cout << *ch << endl;    // prints ch[0]
    cout << ch[0] << endl;  // prints ch[0]
    cout << &ch << endl;    // address of ch
    cout << &ch[0] << endl; // prints string from 0th index
    cout << &ch[1] << endl; // prints string from 1th index
    cout << endl;

    char *c = &ch[0];

    cout << "phase - 2" << endl;
    // prints entire string
    cout << c << endl;

    cout << *c << endl; // prints ch[0]
    cout << &c << endl; // address of c (pointer)
    cout << endl;

    char c1 = 'z';
    char *p1 = &c1;

    cout << "phase - 3" << endl;
    cout << p1 << endl;  // prints string, untill it founds '\0'
    cout << *p1 << endl; // prints c1
    cout << &p1 << endl; // address of p1 (pointer)
    
    return 0;
}