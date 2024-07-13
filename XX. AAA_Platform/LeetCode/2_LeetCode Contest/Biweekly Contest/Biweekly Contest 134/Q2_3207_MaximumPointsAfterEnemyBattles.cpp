// 3207. Maximum Points After Enemy Battles
// LeetCode : https://leetcode.com/problems/maximum-points-after-enemy-battles

#include<bits/stdc++.h>
using namespace std;


#define ll long long
class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if(enemyEnergies[0] > currentEnergy) return 0; // point = 0
        // means point >= 1
        ll totalEnergy = currentEnergy;
        for(int i = 1; i < enemyEnergies.size(); i++) { // not taking 0, to get maximum points
            totalEnergy += enemyEnergies[i] * 1ll;
        }
        return totalEnergy / enemyEnergies[0]; // to maximize pts
    }
};


int main() {
    
    return 0;
}