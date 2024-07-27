// A. Doremy's Paint 3
// Codeforces : https://codeforces.com/problemset/problem/1890/A

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

    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        mp[data]++;
    }

    if(mp.size() > 2) { // size > 2
        cout << "No\n";
    }
    else if(mp.size() == 1) { // size = 1
        cout << "Yes\n";
    }
    else { // size = 2
        int diff = 0;
        for(auto ele : mp) {
            diff = abs(ele.second - diff);
        }
        if(diff <= 1) cout << "Yes\n";
        else cout << "No\n";
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