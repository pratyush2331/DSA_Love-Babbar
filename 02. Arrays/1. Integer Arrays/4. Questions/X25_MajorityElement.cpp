// 169. Majority Element
// LeetCode Problem: https://leetcode.com/problems/majority-element/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, cnt = 0;
        for(int num : nums) {
            if(cnt == 0) candidate = num; // Pick new candidate
            if(candidate == num) cnt++;
            else cnt--; // Cancel out different elements
        }
        return candidate;
    }
};