// 

#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void run() {
    int n;
    cin >> n;

    int pos = 0, neg = 0;
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        if(data == 1) pos++;
        else neg++;
    }

    if((pos >= neg) && (neg % 2 == 0)) cout << 0 << "\n";
    else {
        int cnt = 0;
        while((pos < neg) || (neg % 2 != 0)) {
            cnt++;
            neg--;
            pos++;
        }
        cout << cnt << "\n";
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