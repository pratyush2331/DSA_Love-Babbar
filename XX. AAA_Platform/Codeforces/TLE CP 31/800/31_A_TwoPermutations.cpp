// A. Two Permutations
// Codeforces : https://codeforces.com/problemset/problem/1761/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n, a, b;
    cin >> n >> a >> b;

    if(n == a && n == b) cout << "Yes\n";
    else {
        if(a+b <= n-2) cout << "Yes\n";
        else cout << "No\n";
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