// A. Grasshopper on a Line
// Codeforces : https://codeforces.com/problemset/problem/1837/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

// return smallest number of moves
void run() {
    int x, k;
    cin >> x >> k;

    if(x%k != 0) {
        cout << 1 << "\n" << x << "\n";
    }
    else {
        cout << 2 << "\n";
        cout << x-1 << " " << 1 << "\n";
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