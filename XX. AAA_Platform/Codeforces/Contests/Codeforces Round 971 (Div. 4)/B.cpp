// 

#include<bits/stdc++.h>
using namespace std;

#define F first
#define S second

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

void run() {
    int n;
    cin >> n;
    vector<string> g(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        g[i] = s;
    }

    for(int i = n-1; i >= 0; i--) {
        for(int j = 0; j < 4; j++) {
            if(g[i][j] == '#') cout << (j+1) << " ";
        }
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}