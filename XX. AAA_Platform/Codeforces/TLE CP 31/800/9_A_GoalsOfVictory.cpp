// A. Goals of Victory
// Codeforces : https://codeforces.com/problemset/problem/1877/A

#include<bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << '] (' << #__VA_ARGS__ << '):', dbg_out(__VA_ARGS__)

using ll = long long;

void run() {
    int n;
    cin >> n;

    int sum = 0;
    for(int i = 0; i < n-1; i++) {
        int data;
        cin >> data;
        sum += data;
    }

    cout << sum*(-1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}