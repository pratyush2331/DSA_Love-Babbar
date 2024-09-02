// 3273. Minimum Amount of Damage Dealt to Bob
// LeetCode : https://leetcode.com/problems/minimum-amount-of-damage-dealt-to-bob/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    #define ll long long
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
        int n = damage.size();

        vector<pair<ll, ll>> ratio(n);
        for(int i=0; i<n; i++) {
            ll timeToDefeat;
            if(health[i] % power == 0) timeToDefeat = health[i] / power;
            else timeToDefeat = 1 + (health[i] / power);
            ratio[i] = {damage[i], timeToDefeat};
        }
        
        sort(begin(ratio),end(ratio),[&](pair<ll, ll>&a, pair<ll, ll>&b){
            double impactA = (double)a.first / (double)a.second;
            double impactB = (double)b.first / (double)b.second;
            return impactA > impactB;
        });
        
        long long ans = 0, totalDamage = 0;
        for(auto dmg : damage) {
            totalDamage += dmg;
        }
        for(auto [x, y]: ratio) {
            ans += totalDamage*y;
            totalDamage -= x;
        }
        
        return ans;
    }
};


int main() {
        
    return 0;
}