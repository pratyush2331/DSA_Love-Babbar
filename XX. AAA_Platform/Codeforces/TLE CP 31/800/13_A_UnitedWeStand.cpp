// A. United We Stand
// Codeforces : https://codeforces.com/problemset/problem/1859/A

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dequeue<int> b, c;
    bool isDiff = 0;
    for(int i = 0; i < n; i++) {
        if(isPrime(a[i])) b.push_back(a[i]);
        else c.push_back(a[i]);
        if(i-1 >= 0 && a[i] != a[i-1]) isDiff = 1;
    }

    if(a.empty()) {
        do {
            a.push_back(b.front());
            b.pop_front();
        } while(a[0] == b.front() && !b.empty());
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