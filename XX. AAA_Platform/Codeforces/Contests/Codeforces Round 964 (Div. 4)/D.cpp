// 

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    string s, t;
    cin >> s >> t;

    int i = 0, j = 0;
    while(i < s.length() && j < t.length()) {
        if(s[i] == t[j]) {
            i++;
            j++;
        }
        else if(s[i] == '?') {
            s[i] = t[j];
            i++;
            j++;
        }
        else i++;
    }

    if(i >= s.length() && j < t.length()) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '?') s[i] = 'a';
        }
        cout << s << "\n";
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