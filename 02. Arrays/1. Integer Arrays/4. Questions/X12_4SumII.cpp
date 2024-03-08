// 454. 4Sum II
// LeetCode : https://leetcode.com/problems/4sum-ii/

#include<bits/stdc++.h>

using namespace std;


// method-0 : using unordered_map and splitting it into two 2 sum problem
/*
TC : O(n^3 . logn)
SC : O(1)
*/
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();

        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                mp[nums1[i] + nums2[j]]++;
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                ans += mp[-nums3[i]-nums4[j]];
            }
        }

        return ans;
    }
};



// method-(-1) : using sorting + Binary Search --> giving TLE
/*
TC : O(n^3 . logn)
SC : O(1)
*/
/*
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        sort(nums3.begin(), nums3.end());
        sort(nums4.begin(), nums4.end());

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < n; k++) {
                    int target = 0 - nums1[i] - nums2[j] - nums3[k];
                    int s = 0, e = n-1;
                    int mid = s + (e-s)/2;
                    while(s <= e) {
                        if(nums4[mid] == target) {
                            ans++;
                            int idx = mid-1;
                            while(idx >= s && nums4[idx] == nums4[mid])  {
                                ans++;
                                idx--;
                            }
                            idx = mid+1;
                            while(idx <= e && nums4[idx] == nums4[mid])  {
                                ans++;
                                idx++;
                            }
                            break;
                        }
                        else if(nums4[mid] > target) {
                            e = mid - 1;
                        }
                        else {
                            s = mid + 1;
                        }
                        mid = s + (e-s)/2;
                    }
                }
            }
        }

        return ans;
    }
};
*/


int main() {
    

    return 0;
}