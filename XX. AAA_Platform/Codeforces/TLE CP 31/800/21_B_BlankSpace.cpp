// B. Blank Space
// Codeforces : https://codeforces.com/problemset/problem/1829/B

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// Kadane's Algo variant
void run() {
    int n;
    cin >> n;

    vector<int> a(n);
    int cnt = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            cnt++;
        }
        else {
            ans = max(ans, cnt);
            cnt = 0;
        }
    }
    ans = max(ans, cnt);

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}