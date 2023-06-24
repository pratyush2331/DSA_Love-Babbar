// Coding Ninjas : Odd Square
/*
for n = 4
1357
3571
5713
7135
-------------------------------
for n = 5
13579
35791
57913
79135
91357
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int i = 0; // ye row k liye
    while(i < n) {
        int j = 2*i + 1; // odd lane k liye
        int count = 0;
        while(count < n) {
            cout << j%(2*n); // mod kr ke
            j += 2;
            count++;
        }

        cout << endl;

        i++;
    }
    return 0;
}