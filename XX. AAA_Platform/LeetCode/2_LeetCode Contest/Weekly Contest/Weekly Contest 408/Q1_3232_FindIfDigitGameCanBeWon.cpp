// 3232. Find if Digit Game Can Be Won
// LeetCode : https://leetcode.com/problems/find-if-digit-game-can-be-won

#include<bits/stdc++.h>
using namespace std;

using ll = long long;


class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
        int n = nums.size();
        int single = 0, doubl = 0;

        for(int i = 0; i < n; i++) {
            int digit = nums[i];
            int cnt = 0;
            while(digit) {
                cnt++;
                digit /= 10;
            }
            if(cnt == 1) single += nums[i];
            else doubl += nums[i];
        }
        return single != doubl;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
        
    return 0;
}