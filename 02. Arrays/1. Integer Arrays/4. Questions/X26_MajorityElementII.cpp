// 229. Majority Element II
// LeetCode : https://leetcode.com/problems/majority-element-ii/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0, cnt1 = 0;
        int candidate2 = 0, cnt2 = 0;
        for(int num : nums) {
            if(cnt1 == 0 && num != candidate2) candidate1 = num;
            else if(cnt2 == 0 && num != candidate1) candidate2 = num;

            if(num == candidate1) cnt1++;
            else if(num == candidate2) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = 0, cnt2 = 0;
        for(int num : nums) {
            if(num == candidate1) cnt1++;
            else if(num == candidate2) cnt2++;
        }

        vector<int> ans;
        int n = nums.size();
        if(cnt1 > n/3) ans.push_back(candidate1);
        if(cnt2 > n/3) ans.push_back(candidate2);
        return ans;
    }
};