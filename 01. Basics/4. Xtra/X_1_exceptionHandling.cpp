// Exception Handling : try, catch, throw

#include<bits/stdc++.h>

using namespace std;

int main() {
    int num, den;
    cout << "Enter numerator & denominator : ";
    cin >> num >> den;

    int res = 0; // by default zero will return
    try {
        if(den == 0) throw den;
        res = num/den; // possibility of error : as diivision happens here
    }
    catch(int ex) { // catching the exception if it's thrown
        cout << "Exception : Division by zero is not allowed !" << endl;
    }

    cout << "Division is : " << res << endl;

    return 0;
}