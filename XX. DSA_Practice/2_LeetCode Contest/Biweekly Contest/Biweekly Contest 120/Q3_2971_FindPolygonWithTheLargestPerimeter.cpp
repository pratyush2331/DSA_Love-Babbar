// 2971. Find Polygon With the Largest Perimeter
// LeetCode : https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

#include<bits/stdc++.h>

using namespace std;


class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        
        // processing...
        sort(nums.begin(), nums.end());
        
        long long sum = 0;
        for(int ele :  nums) {
            sum += ele;
        }
        
        for(int i = nums.size()-1; i >= 0; i--) {
            sum -= nums[i];
            
            if(sum > nums[i]) {
                return sum+nums[i];
            }
        }
        
        return -1;
    }
};


int main() {
    

    return 0;
}