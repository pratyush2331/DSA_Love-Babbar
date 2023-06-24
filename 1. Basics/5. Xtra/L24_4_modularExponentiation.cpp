// CodeStudio : Modular Arithmetic

#include <bits/stdc++.h> 
using namespace std;

/*
sample i/p :
4          <----------         test case (not reqd)
3 1 2
4 3 10
5 2 10 
2 5 4

sample o/p :
1
4
5
0
*/

int modularExponentiation(int x, int n, int m) {
	// Write your code here.
    int res = 1;
    
    while(n) {
        if(n & 1) { // for odd power
            res = (1LL * res * x) % m;
        }
        
        x = (1LL * x * x) % m;
        n = n >> 1;
    }
    
    return res;
}

int main() {
    int x, n, m;
    cout << "Enter number : ";
    cin >> x;
    cout << "Enter power : ";
    cin >> n;
    cout << "Enter mod value : ";
    cin >> m;

    cout << "(" << x << "^" << n << ") % " << m << " = " << modularExponentiation(x, n, m) << endl;
}