// 3179. Find the N-th Value After K Seconds
// LeetCode : https://leetcode.com/problems/find-the-n-th-value-after-k-seconds

#include<bits/stdc++.h>
using namespace std;


#define ll long long
#define MOD 1000000007

class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector<ll> ans(n, 1);
        for(int i = 1; i <= k; i++) {
            for(int idx = 0; idx < n; idx++) {
                if(idx > 0) ans[idx] = (ans[idx] + ans[idx-1])%MOD;
                ans[idx] = ans[idx]%MOD;
            }
        }
        return ans[n-1]%MOD;
    }
};


int main() {
    
    return 0;
}