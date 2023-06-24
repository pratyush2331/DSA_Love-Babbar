// macros in C++

#include<iostream>
using namespace std;

// object-like macros
#define PI 3.1416

// multiline macros
#define ELE 1,\
2,3

// function-like macros
#define MIN(a,b) ((a<b) ? a : b)

// chain macros
#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138

#define  AREA(r)  (PI*(r)*(r))


int main() {
    cout << "value of pi : " << PI << endl;

    int arr[] = {ELE};

    for(int i = 0; i < 3; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "min : " << MIN(arr[0], arr[1]) << endl;

    cout << "I have "<< INSTAGRAM << "K followers on Instagram!" << endl;

    float r = 7;    // radius of circle
       
    cout<<"Area of Circle with radius " << r <<": "<< AREA(r);
    
    return 0;
}