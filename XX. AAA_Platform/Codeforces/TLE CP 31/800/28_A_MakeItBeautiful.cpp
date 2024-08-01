// A. Make it Beautiful
// Codeforces : https://codeforces.com/problemset/problem/1783/A

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

    sort(a.begin(), a.end());
    if(a[0] == a[n-1]) { // impossible case
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    int s = 0, e = n-1, lastEle = 101;
    while(s <= e) {
        if(a[e] != lastEle) {
            cout << a[e] << " ";
            lastEle = a[e--];
        }
        else {
            cout << a[s] << " ";
            lastEle = a[s++];
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}