// 3273. Minimum Amount of Damage Dealt to Bob
// LeetCode : https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/

#include<bits/stdc++.h>
using namespace std;


class Solution {
    #define ll long long

public:
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();

        vector<pair<ll, ll>> fact(n);
        for(int i = 0; i < n; i++) {
            ll time = (health[i] % power == 0) ? health[i] / power : 1 + (health[i] / power);
            fact[i] = {damage[i], time};
        }

        sort(begin(fact), end(fact), [&](pair<ll, ll>& a, pair<ll, ll>& b){
            return (double)a.first / (double)a.second > (double)b.first / (double)b.second;
        });

        ll ans = 0, totDmg = 0;
        for(auto dmg : damage) {
            totDmg += dmg;
        }

        for(auto [dmg, time] : fact) {
            ans += totDmg * time;
            totDmg -= dmg;
        }

        return ans;
    }
};


int main() {
        
    return 0;
}