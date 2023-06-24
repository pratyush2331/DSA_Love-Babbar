// Pointers - Play

#include<iostream>
using namespace std;

int main() {
    // /*
    int i = 5;
    // int *p = &i;
    int *p = 0;     // int *p = NULL;
    p = &i;

    cout << "value of p is " << p << endl;
    cout << "value of *p is " << *p << endl;
    // */

// -------------------------------------------------------------------------------------------

    /*
    int num = 5;
    
    int a = num;
    cout << "a Before : " << num << endl;
    a++;
    cout << "a After : " << num << endl;

    int *p = &num;
    cout << "Before : " << num << endl;
    (*p)++;
    cout << "After : " << num << endl;
    */

// -------------------------------------------------------------------------------------------

    /*
    int a = 5;
    int &b = a;     // b is reference to a

    cout << "Before" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    a++;
    b++;
    cout << "After" << endl;
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    */

// -------------------------------------------------------------------------------------------

    /*
    int a = 5;
    int *p = &a;

    int *q = p;     // copying pointer p to q

    cout << p << " - " << q << endl;
    cout << *p << " - " << *q << endl;
    */

// -------------------------------------------------------------------------------------------

    // important concept
    // /*
    // int arr[] = {10, 20};
    // int *p = arr;
    // ++*p;
    // printf("arr[0] = %d, arr[1] = %d, *p = %d", arr[0], arr[1], *p);

    // int arr[] = {10, 20};
    // int *p = arr;
    // *p++;     // p++; both are same!
    // printf("arr[0] = %d, arr[1] = %d, *p = %d", arr[0], arr[1], *p);

    // int arr[] = {10, 20};
    // int *p = arr;
    // *++p;
    // printf("arr[0] = %d, arr[1] = %d, *p = %d", arr[0], arr[1], *p);

    // int arr[] = {10, 20};
    // int *p = arr;
    // ++*p++;
    // printf("arr[0] = %d, arr[1] = %d, *p = %d", arr[0], arr[1], *p);
    // */

    return 0;
}