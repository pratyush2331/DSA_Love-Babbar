// 3301. Maximize the Total Height of Unique Towers
// leetCode : https://leetcode.com/problems/maximize-the-total-height-of-unique-towers

#include<bits/stdc++.h>
using namespace std;


#define ll long long
class Solution {
public:
    long long maximumTotalSum(vector<int>& ht) {
        // IMP : height can't be <= 0
        ll sum = 0LL;

        sort(ht.begin(), ht.end());
        unordered_map<ll, ll> mp;
        for (int i =  ht.size()-1; i >= 0; i--) {
            if (mp.find(ht[i]) == mp.end()) {
                mp[ht[i]] = 1;
                sum += 1LL * ht[i];
            }
            else { // already present
                // Do Binary Search on height to find maxm
                ll s = 1LL, e = 1LL * ht[i];
                ll possible_ht = -1LL;
                
                while (s <= e) {
                    ll mid = s + (e - s) / 2;
                    if (mp.find(mid) == mp.end()) {
                        possible_ht = mid;
                        s = mid + 1;
                    } else {
                        e = mid - 1;
                    }
                }

                if (possible_ht == -1LL) { // not found
                    return -1LL;
                }

                // got the maxm possible height
                mp[possible_ht] = 1;
                sum += 1LL * possible_ht;
            }
        }

        return sum;
    }
};


int main() {
    
    return 0;
}