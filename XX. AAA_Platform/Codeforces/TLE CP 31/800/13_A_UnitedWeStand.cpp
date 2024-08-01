// A. United We Stand
// Codeforces : https://codeforces.com/problemset/problem/1859/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    vector<int> a(n);
    int mini = INT_MAX, maxi = INT_MIN;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mini = min(mini, a[i]);
        maxi = max(maxi, a[i]);
    }

    if(mini == maxi) { // impossible case --> all elts are equal
        cout << -1 << "\n";
        return;
    }

    vector<int> b, c;
    for(int i = 0; i < n; i++) {
        if(a[i] == maxi) c.push_back(a[i]);
        else b.push_back(a[i]);
    }

    // answer printing
    cout << b.size() << " " << c.size() << "\n";
    for(auto ele : b) {
        cout << ele << " ";
    }
    cout << "\n";
    for(auto ele : c) {
        cout << ele << " ";
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