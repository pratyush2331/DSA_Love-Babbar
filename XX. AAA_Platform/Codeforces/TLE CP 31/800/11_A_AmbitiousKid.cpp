// 

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    vector<int> A(n);
    int mini = INT_MAX;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        mini = min(mini, abs(A[i]));
    }

    cout << mini << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;
    while(t--) run();
        
    return 0;
}