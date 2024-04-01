// [Div 3 - Round 661] C. Boats Competition
// COdeforces : https://codeforces.com/problemset/problem/1399/C

#include<bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        unordered_map<int,int> mp;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            mp[x]++;
        }

        int maxi = 0;
        for(int s = 2; s <= (2*n); s++) { // s ranges from [2, 2*n]
            int total = 0;
            for(auto ele : mp) {
                int other = s - ele.first;
                if(other >= 1 && mp.find(other) != mp.end()) total += min(ele.second, mp[other]);
            }
            total = total >> 1;
            maxi = max(maxi, total);
        }

        cout << maxi << "\n";
    }

    return 0;
}