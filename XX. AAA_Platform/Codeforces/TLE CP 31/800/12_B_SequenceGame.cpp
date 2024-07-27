// B. Sequence Game
// Codeforces : https://codeforces.com/problemset/problem/1862/B

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> a;
    a.push_back(b[0]);
    for(int i = 1; i < n; i++) {
        if(b[i] < b[i-1]) {
            a.push_back(b[i]);
        }
        a.push_back(b[i]);
    }
    
    cout << a.size() << "\n";
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
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