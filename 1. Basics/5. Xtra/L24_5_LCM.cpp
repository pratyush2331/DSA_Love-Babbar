// LCM of 2 numbers

#include<iostream>
using namespace std;

int lcm(int a, int b) {
    int maxi = a>b ? a : b;
    while(1) {
        if(maxi%a == 0 && maxi%b == 0) {
            return maxi;
        }
        maxi++;
    }
}

int main() {
    int a, b;
    cout << "Enter a & b : ";
    cin >> a >> b;

    if(a == 0 || b == 0) {
        cout << "LCM of " << a << " & " << b << " is not defined !" << endl;
    }
    else {
        cout << "LCM of " << a << " & " << b << " is " << lcm(a, b) << endl;
    }
    
    return 0;
}