// Friend function

#include<bits/stdc++.h>

using namespace std;

class Distance {
    int meters;

    public:
    Distance() {
        meters = 0;
    }
    void displayData() {
        cout << "Meters value: " << meters << endl;
    }
    // prototype of friend function
    friend void addvalue(Distance &d);
};

// definition of friend fuction as normal function
void addvalue(Distance& d) { // pass by reference
    d.meters += 5;
}

int main() {
    Distance d1;
    d1.displayData(); 

    // calling friend fuction
    addvalue(d1);
    
    d1.displayData();

    return 0;
}