// C. Password Cracking
// Codeforces : https://codeforces.com/contest/2013/problem/C

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

bool ask(string s) {
    cout << "? " << s << endl;
    cout.flush();
    
    bool res;
    cin >> res;
    return res;
}

void run() {
    int n;
    cin >> n;
    string password = "";
    bool flag = true;

    for(int i = 0; i < n; i++) {
        if(flag) {
            if(ask(password + '0')) {
                password += '0';
                continue;
            }
            if(ask(password + '1')) {
                password += '1';
                continue;
            }
            flag = false;
        }
        if(!flag) {
            if(ask('0' + password)) {
                password = '0' + password;
                continue;
            }
            else{
                password = '1' + password;
            }
        }
    }

    cout << "! " << password << "\n";
    cout.flush();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}