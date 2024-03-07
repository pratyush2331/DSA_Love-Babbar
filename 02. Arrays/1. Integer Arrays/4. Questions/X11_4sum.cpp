// 18. 4Sum
// LeetCode : https://leetcode.com/problems/4sum/

#include<bits/stdc++.h>

using namespace std;


// method-1 : using 4 pointers (2 ptr{i,j} & 2 ptr{s,e})
/*
TC : O(n^3)
SC : O(1)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) { // 1st pointer
            for(int j = i+1; j < n; j++) { // 2nd pointer
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int s = j+1, e = n-1; // 2 more pointers
                while(s < e) {
                    if(nums[s] + nums[e] == newTarget) {
                        ans.push_back({nums[i], nums[j], nums[s], nums[e]});
                        while(s < e && nums[s] == nums[s+1]) s++;
                        while(s < e && nums[e] == nums[e-1]) e--;
                        s++;
                        e--;
                    }
                    else if(nums[s] + nums[e] > newTarget) {
                        e--;
                    }
                    else {
                        s++;
                    }
                }
                while(j+1 < n && nums[j] == nums[j+1]) j++;
            }
            while(i+1 < n && nums[i] == nums[i+1]) i++;
        }

        return ans;
    }
};



// method-0 : using Binary Search
/*
TC : O(n^3 . logn)
SC : O(1)
*/
/*
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                for(int k = j+1; k < n; k++) {
                    long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j] - (long long)nums[k];
                    int s = k+1, e = n-1;
                    int mid = s + (e-s)/2;
                    while(s <= e) {
                        if(nums[mid] == newTarget) {
                            ans.push_back({nums[i], nums[j], nums[k], nums[mid]});
                            break;
                        }
                        else if(nums[mid] > newTarget) {
                            e = mid-1;
                        }
                        else {
                            s = mid + 1;
                        }
                        mid = s + (e-s)/2;
                    }
                    while(k+1 < n && nums[k] == nums[k+1]) k++;
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