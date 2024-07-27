// B. Angry Monk
// Codeforces : https://codeforces.com/contest/1992/problem/B

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

    vector<int> v(k);
    for(int i = 0; i < k; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int ans = 0;
    for(int i = 0; i < k-1; i++) {
        ans += 2*v[i] - 1;
    }

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