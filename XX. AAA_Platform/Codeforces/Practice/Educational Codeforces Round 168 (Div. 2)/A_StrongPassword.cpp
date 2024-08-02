// A. Strong Password
// Codeforces : https://codeforces.com/contest/1997/problem/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    string s;
    cin >> s;

    string ans = "";
    ans += s[0];
    bool flag = 0;
    for(int i = 0; i < s.length()-1; i++) {
        if(!flag && s[i] == s[i+1]) {
            if(s[i] == 'a') ans += 'z';
            else ans += 'a';
            ans += s.substr(i+1);
            flag = 1;
            break;
        }
        ans += s[i+1];
    }

    if(!flag) {
        if(ans[ans.length()-1] == 'a') ans += 'z';
        else ans += 'a';
        flag = 1;
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