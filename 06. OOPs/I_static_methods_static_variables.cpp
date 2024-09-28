// Static methods and Static variables

#include<bits/stdc++.h>
using namespace std;

/*
Key Points About Static Variables:
1. They are shared by all instances of a class.
2. They are initialized outside the class definition.
3. They can be accessed using the class name (ClassName::staticVariable), though they can also be accessed using an object reference.
*/

class Counter {
public:
    static int count; // static variable declaration

    Counter() {
        count++; // Increment count when a new object is created
    }

    static void showCount() {
        cout << "Number of objects created: " << count << endl;
    }
};

// Initialize the static variable outside the class
int Counter::count = 0;

int main() {
    Counter c1; // count = 1
    Counter c2; // count = 2
    Counter c3; // count = 3

    // Accessing static variable via class name (preferred)
    Counter::showCount();  // Output: Number of objects created: 3

    return 0;
}
