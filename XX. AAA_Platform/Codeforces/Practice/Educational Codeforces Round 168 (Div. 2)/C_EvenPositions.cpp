// https://codeforces.com/contest/1997/problem/C
// Codeforces : https://codeforces.com/contest/1997/problem/C

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    stack<int> st; // store starting index
    int ans = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '(') {
            st.push(i);
        }
        else if(s[i] == ')') {
            ans += i-st.top();
            st.pop();
        }
        else if(s[i] == '_') {
            if(st.empty()) {
                st.push(i);
            }
            else {
                ans += i-st.top();
                st.pop();
            }
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