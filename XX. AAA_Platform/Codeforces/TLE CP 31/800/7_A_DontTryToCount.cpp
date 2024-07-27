// A. Don't Try to Count
// Codeforces : https://codeforces.com/problemset/problem/1881/A

#include<bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> 
void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << '[' << __FILE__ << ':' << __LINE__ << '] (' << #__VA_ARGS__ << '):', dbg_out(__VA_ARGS__)

using ll = long long;

void run() {
    int m, n;
    cin >> m >> n;

    string s1, s2;
    cin >> s1 >> s2;

    for(int ops = 0; ops <= 5; ops++) { // worst case x--> 5 times
        if(s1.find(s2) != -1) {
            cout << ops << "\n";
            return;
        }
        s1 += s1;
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