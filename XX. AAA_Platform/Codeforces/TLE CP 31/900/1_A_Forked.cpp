// A. Forked!
// Codeforces : https://codeforces.com/problemset/problem/1904/A

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void run() {
    int a, b, xk, yk, xq, yq;
    cin >> a >> b >> xk >> yk >> xq >> yq;

    set<pair<int,int>> mpk, mpq;
    vector<pair<int,int>> del = {{a, b}, {a, -b}, {-a, b}, {-a, -b},
                                 {b, a}, {b, -a}, {-b, a}, {-b, -a}};
    
    for(auto ele : del) {
        int delx = ele.first;
        int dely = ele.second;
        mpk.insert({xk+delx, yk+dely});
        mpq.insert({xq+delx, yq+dely});
    }

    int cnt = 0;
    for(auto ele : mpk) {
        if(mpq.find(ele) != mpq.end()) cnt++;
    }
    cout << cnt << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
        
    return 0;
}