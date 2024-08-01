// C. Prepend and Append
// Codeforces : https://codeforces.com/problemset/problem/1791/C

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    string str;
    cin >> str;

    int s = 0, e = n-1;
    while(s < e && str[s] != str[e]) {
        s++;
        e--;
    }
    
    cout << e-s+1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}