// A. Desorting
// Codeforces : https://codeforces.com/problemset/problem/1853/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int mini = INT_MAX;
    for(int i = 1; i < n; i++) {
        mini = min(mini, a[i] - a[i-1]);
    }

    if(mini < 0) cout << 0 << "\n";
    else {
        cout << mini/2 + 1 << "\n";
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