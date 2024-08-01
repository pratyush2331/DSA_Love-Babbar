// A. One and Two
// Codeforces : https://codeforces.com/problemset/problem/1788/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    vector<int> a(n);
    int suff2Sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 2) suff2Sum++;
    }

    int pre2Sum = 0;
    for(int i = 0; i <= n-1; i++) {
        if(a[i] == 2) {
            pre2Sum++;
            suff2Sum--;
        }
        if(pre2Sum == suff2Sum) {
            cout << (i+1) << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}