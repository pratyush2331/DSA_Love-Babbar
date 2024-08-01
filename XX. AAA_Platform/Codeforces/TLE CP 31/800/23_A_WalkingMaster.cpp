// A. Walking Master
// Codeforces : https://codeforces.com/problemset/problem/1806/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// method-1
void run() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if(b > d) cout << -1 << "\n";
    else if((a + (d - b)) < c) cout << -1 << "\n";
    else cout << ((d-b) + ((a+(d-b))-c)) << "\n";
}

// method-0
/*
void run() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int cnt = 0;

    int factor = d - b;
    if(factor < 0) {
        cout << -1 << "\n";
        return;
    }

    a += factor;
    b += factor;
    cnt += factor;

    factor = a - c;
    cnt += factor;

    if(factor < 0) cout << -1 << "\n";
    else cout << cnt << "\n";
}
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}