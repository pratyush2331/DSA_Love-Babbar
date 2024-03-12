// 287. Find the Duplicate Number
// LeetCode : https://leetcode.com/problems/find-the-duplicate-number/

#include<iostream>
using namespace std;


// method-2 : using visited index/number
/*
TC : O(n) --> linear time to traverse the nums
SC:  O(1)
*/
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int n = nums.size();
        for(int ele : nums) {
            int idx = abs(ele)-1;
            if(nums[idx] < 0) return idx+1;
            nums[idx] = -nums[idx];
        }
        return -1;
    }
};



// method-1 : using slow and fast pointer
/*
TC : O(n) --> linear time to traverse the nums
SC:  O(1)
*/
/*
class Solution {
    public:
    int findDuplicate(vector<int>& nums) {
// method-1 : using map
        int slow = nums[0];
        int fast = nums[0];
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        fast = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
*/



// method-1 : using map
/*
TC : O(n) --> linear time to traverse the nums
SC:  O(n) --> map space
*/
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> mp(n, 0);
        for(int i = 0; i < n; i++) {
            if(mp[nums[i]] == 1) {
                return nums[i];
            }
            mp[nums[i]] = 1;
        }
        return -1;
    }
};
*/



// method-0 : greedy
/*
TC : O(n.logn) --> sorting time
SC:  O(logn) --> sorting space
*/
/*
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n; i++) {
            if(nums[i] == nums[i+1]) {
                return nums[i];
            }
        }
        return -1;
    }
};
*/


int main() {
    
    return 0;
}