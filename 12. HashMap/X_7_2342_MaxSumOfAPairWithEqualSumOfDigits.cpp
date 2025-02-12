// 2342. Max Sum of a Pair With Equal Sum of Digits
// LeetCode : https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/

#include<bits/stdc++.h>
using namespace std;


// method : using HashMap
/*
TC : O(n.logm)
SC : O(logm) = O(1)

n --> nums.length
m --> max num value
*/
class Solution {
    int getDigitSum(int num) {
        int sum = 0;
        while(num) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int, int> mp; // {sum, max_num_sum}
        for(int& num : nums) {
            int sum = getDigitSum(num);
            if(mp.count(sum)) ans = max(ans, num + mp[sum]);
            mp[sum] = max(mp[sum], num);
        }
        return ans;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    cin >> t;
    while(t--) run();
    
    return 0;
}