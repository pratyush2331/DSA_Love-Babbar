// 3273. Minimum Amount of Damage Dealt to Bob
// LeetCode : https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    #define ll long long
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();

        vector<pair<ll, ll>> a;
        for(int i=0; i<n; i++) {
            a.push_back({damage[i], (health[i]+power-1)/power});
        }
        
        sort(begin(a),end(a),[&](pair<ll, ll>&x, pair<ll, ll>&y){
            return x.first*y.second>x.second*y.first;
        });
        
        long long ans = 0, res = 0;
        for(auto [x, y]: a) res+=x;
        for(auto [x, y]: a) {
            ans+=res*y;res-=x;
        }
        
        return ans;
    }
};


int main() {
        
    return 0;
}