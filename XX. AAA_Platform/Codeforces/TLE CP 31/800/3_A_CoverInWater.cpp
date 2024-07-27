// A. Cover in Water
// Codeforces : https://codeforces.com/problemset/problem/1900/A

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

    string s;
    cin >> s;

    int cntEmpty = 0, cntConsecutive = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '.') { // consecutive empty
            cntConsecutive++;
            cntEmpty++;
        }
        else {
            cntConsecutive = 0;
        }

        if(cntConsecutive == 3) {
            cout << "2\n";
            return;
        }
    }
    cout << cntEmpty << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}