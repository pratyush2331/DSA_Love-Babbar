// A. Array Coloring
// Codeforces : https://codeforces.com/problemset/problem/1857/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// odd is responsible for splitting in 2 parts
void run() {
    int n;
    cin >> n;

    int odd = 0;
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        if(data&1) odd++;
    }

    (odd&1) ? cout << "NO\n" : cout << "YES\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}