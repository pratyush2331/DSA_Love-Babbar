// 

#include<iostream>
using namespace std;

class StarWars
{
    public:
    int i;
    StarWars(int x)    // constructor
    { 
        i = x; 
    }

    int falcon() const  // constant function
    { 
        /* 
            can do anything but will not
            modify any data members
        */
        cout << "Falcon has left the Base";
    }

    int gamma()
    { 
        i++; 
    }
};

int main() {
    StarWars objOne(10);        // non const object
    const StarWars objTwo(20);      // const object

    objOne.falcon();     // No error
    objTwo.falcon();     // No error

    cout << objOne.i << objTwo.i;

    objOne.gamma();     // No error
    // objTwo.gamma();     // Compile time error
}