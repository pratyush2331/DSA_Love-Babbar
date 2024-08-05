// A. Creating Words
// Codeforces : https://codeforces.com/contest/1985/problem/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    string a, b;
    cin >> a >> b;

    swap(a[0], b[0]);

    cout << a << " " << b << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}