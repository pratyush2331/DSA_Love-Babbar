// 

#include<iostream>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    ll odd = 0, even = 0;
    int oddLen = 0, evenLen = 0;
    for(int i = 0; i < n; i++) {
        ll num;
        cin >> num;

        if((i+1)&1) odd += num, oddLen++;
        else even += num, evenLen++;
    }

    bool flag = 0;
    if(n&1) {
        if((odd > even) && (odd%oddLen == 0 && even%evenLen == 0 && odd/oddLen == even/evenLen)) flag = 1;
    }
    else {
        if((odd == even) && (odd%oddLen == 0 && even%evenLen == 0)) flag = 1;;
    }

    if(flag) cout << "Yes\n";
    else cout << "No\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}