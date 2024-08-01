// A. Buttons
// Codeforces : https://codeforces.com/problemset/problem/1858/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int a, b, c;
    cin >> a >> b >> c;

    if(c&1) {
        (a >= b) ? cout << "First\n" : cout << "Second\n";
    }
    else {
        (a > b) ? cout << "First\n" : cout << "Second\n";
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}