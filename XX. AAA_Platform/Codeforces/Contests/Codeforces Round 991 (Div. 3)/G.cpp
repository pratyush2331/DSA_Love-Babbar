// // 

// #include<bits/stdc++.h>
// using namespace std;

// #define F first
// #define S second

// using ll = long long;
// using pii = pair<int, int>;
// using pll = pair<ll, ll>;

// void run() {
//     int n;
//     cin >> n;

//     vector<int> deg(n+1, 0);
//     int ans = 0;
//     for(int i = 1; i <= n-1; i++) {
//         int u, v;
//         cin >> u >> v;

//         deg[u]++;
//         deg[v]++;

//         ans = max(ans, deg[u]);
//         ans = max(ans, deg[v]);
//         ans = max(ans, deg[u] + deg[v] - 2);
//     }

//     cout << ans << "\n";
// }

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
    
//     int t = 1;
//     cin >> t;
//     while(t--) run();
    
//     return 0;
// }