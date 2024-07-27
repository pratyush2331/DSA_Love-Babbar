// A. Halloumi Boxes
// Codeforces : https://codeforces.com/problemset/problem/1903/A

#include<bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << '] (' << #__VA_ARGS__ << '):', dbg_out(__VA_ARGS__)

using ll = long long;

void run() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    bool flag = 0;
    for(int i = 0; i < n-1; i++) {
        if(a[i] > a[i+1]) flag = 1;
    }

    if(flag == 0) {
        cout << "YES\n";
    }
    else {
        (k == 1) ? cout << "NO\n" : cout << "YES\n";
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