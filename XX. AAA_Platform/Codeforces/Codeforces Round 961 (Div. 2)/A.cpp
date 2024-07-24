// 

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        int cnt = 0;
        if(k == 0) cnt = 0;
        else {
            int rows = n, num = 1, i = 1;
            while(k > 0) {
                num--;
                k -= rows;
                if(num == 0) {
                    num = 2;
                    rows = n-i;
                    i++;
                }
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
    
    return 0;
}