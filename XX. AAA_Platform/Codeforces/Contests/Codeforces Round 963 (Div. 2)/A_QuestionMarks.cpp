// A. Question Marks
// Codeforces : https://codeforces.com/contest/1993/problem/0

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    string s;
    cin >> s;


    unordered_map<char,int> mp;
    for(int i = 0; i < 4*n; i++) {
        mp[s[i]]++;
    }

    int ans = 0;
    for(auto ele : mp) {
        if(ele.first != '?') { // either A, B, C, D
            ans += min(ele.second, n);
        }
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