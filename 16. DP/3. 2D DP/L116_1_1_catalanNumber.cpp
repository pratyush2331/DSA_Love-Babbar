// nth Catalan Number
// article : https://cp-algorithms.com/combinatorics/catalan-numbers.html
// pepcoding Video : https://www.youtube.com/watch?v=eUw9A1wsFg8

/*
Catalan Number :  1, 1, 2, 5, 14, 42, ...

C0 -> 1
C1 -> 1
C2 -> 2
C3 -> 5
C4 -> 14
C5 -> 42
........
*/

#include<iostream>
#include<vector>
using namespace std;

long long catalanNumber(int n) {
    if(n <= 1)
        return 1;
    
    vector<long long> catalan(n+1, 0);

    catalan[0] = catalan[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            catalan[i] += catalan[j] * catalan[i-j-1];
        }
    }

    return catalan[n];
}

int main() {
    int n;
    cin >> n;

    cout << catalanNumber(n) << endl;
    
    return 0;
}