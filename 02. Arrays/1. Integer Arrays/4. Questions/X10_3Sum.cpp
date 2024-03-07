// 15. 3Sum
// LeetCode : https://leetcode.com/problems/3sum

#include<bits/stdc++.h>

using namespace std;


// method-1 : 2 pointer logic will work because we don't have to return the index.
/*
TC : O(n^2)
SC : O(1)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) { // 1st pointer
            int target = -nums[i];
            int s = i+1, e = n-1; // 2 more pointers
            while(s < e) {
                if(nums[s] + nums[e] == target) {
                    ans.push_back({nums[i], nums[s], nums[e]});
                    while(s < e && nums[s] == nums[s+1]) s++;
                    while(s < e && nums[e] == nums[e-1]) e--;
                    s++;
                    e--;
                }
                else if(nums[s] + nums[e] > target) {
                    e--;
                }
                else {
                    s++;
                }
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }

        return ans;
    }
};



// method-0 : binary search logic will work because we don't have to return the index.
/*
TC : O(n^2 . logn)
SC : O(1)
*/
/*
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int s = j+1;
                int e = n-1;
                int mid = s + (e-s)/2;
                while(s <= e) {
                    if(nums[i] + nums[j] + nums[mid] == 0) {
                        ans.push_back({nums[i], nums[j], nums[mid]});
                        break;
                    }
                    else if(nums[i] + nums[j] + nums[mid] > 0) {
                        e = mid-1;
                    }
                    else {
                        s = mid+1;
                    }
                    mid = s + (e-s)/2;
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }

        return ans;
    }
};
*/


int main() {
    

    return 0;
}