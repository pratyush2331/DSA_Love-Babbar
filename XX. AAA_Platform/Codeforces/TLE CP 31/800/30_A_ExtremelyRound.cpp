// A. Extremely Round
// Codeforces : https://codeforces.com/problemset/problem/1766/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// method-1
void run() {
    string s;
    cin >> s;

    cout << (s[0] - '0') + 9*(s.length()-1) << "\n";
}

// method-0
/*
void run() {
    int n;
    cin >> n;

    int temp = n;
    int digits = 0, lastDigit;
    while(temp) {
        lastDigit = temp%10;
        temp /= 10;
        digits++;
    }

    // formula
    int ans = lastDigit + 9*(digits-1);
    cout << ans << "\n";
}
*/

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}