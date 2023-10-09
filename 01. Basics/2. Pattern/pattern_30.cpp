// Coding Ninjas : Pattern Question
/*
for n = 3
*
*1*
*121*
*12321*
*121*
*1*
*

for n = 5
*
*1*
*121*
*12321*
*1234321*
*123454321*
*1234321*
*12321*
*121*
*1*
*
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    cout << "*" << endl;
    int i = 0;
    while(i < n) {
        cout << "*";

        int j = 1;
        while(j <= i+1) {
            cout << j;
            j++;
        }

        int k = j-2;
        while(k >= 1) {
            cout << k;
            k--;
        }

        cout << "*";

        cout << endl;

        i++;
    }

    i = n-1;
    while(i > 0) {
        cout << "*";

        int j = 1;
        while(j < i+1) {
            cout << j;
            j++;
        }

        int k = j-2;
        while(k >= 1) {
            cout << k;
            k--;
        }

        cout << "*";

        cout << endl;
        
        i--;
    }
    
    cout << "*";

    return 0;
}