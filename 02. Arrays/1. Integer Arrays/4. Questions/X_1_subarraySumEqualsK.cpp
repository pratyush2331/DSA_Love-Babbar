// 560. Subarray Sum Equals K
// LeetCode : https://leetcode.com/problems/subarray-sum-equals-k/

/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
*/

// Optimal Solution - TC : O(n), SC : O(1)
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> preSum;
        preSum[0] = 1; // 0 ek baar aaya hai
        int sum = 0, ans = 0;
        for(auto i : nums) {
            sum += i;
            if(preSum.find(sum-k) != preSum.end()) {
                ans += preSum[sum-k];
            }
            preSum[sum]++;
        }
        return ans;
    }

    // for fast i/p - o/p
    Solution() {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        wcin.tie(nullptr);
        cerr.tie(nullptr);
        wcerr.tie(nullptr);
        clog.tie(nullptr);
        wclog.tie(nullptr);
    }
};

// Naive Solution - TC : O(n2), SC : O(1)
// giving TLE in LeetCode in 87th test case out of 93
/*
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }
};
*/

int main() {

    return 0;
}