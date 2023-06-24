// Coding Ninjas : Pattern Question
/*
for n = 5
  *
 ***
*****
 ***
  *
--------------------------------------------------------
for n = 9
    *
   ***
  *****
 *******
*********
 *******
  *****
   ***
    *
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    // Upper trinagle
    int i = 0;
    while(i < (n+1)/2) {
        int j = (n+1)/2 - 1;
        while(j > i) {
            cout << " ";
            j--;
        }

        int k = 2*i + 1;
        while(k > 0) {
            cout << "*";
            k--;
        }
        cout << endl;
        i++;
    }

    // Lower Pattern
    i = 0;
    while(i < (n+1)/2 - 1) {
        int j = i+1;
        while(j > 0) {
            cout << " ";
            j--;
        }

        int k = 2*i + 1;
        while(k <= n-2) {
            cout << "*";
            k++;
        }
        cout << endl;
        i++;
    }

    return 0;
}