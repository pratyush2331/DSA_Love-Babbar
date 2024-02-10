// 2848. Points That Intersect With Cars
// LeetCode : https://leetcode.com/problems/points-that-intersect-with-cars/

#include<iostream>
using namespace std;


//         [[4,4],[9,10],[9,10],[3,8]]
//         [[2,5],[3,8],[1,6],[4,10]]

class Solution {
    public:
    int numberOfPoints(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        
        
        int ans = nums[0][1] - nums[0][0] + 1, maxLast = nums[0][1];
        // cout << ans << " ";
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i][0] <= maxLast)  {
                if(nums[i][1] > maxLast)
                    ans += nums[i][1] - maxLast;
                else
                    ans += 0;
                // cout << ans << " ";
                maxLast = max(maxLast, nums[i][1]);
            }
            else  {
                ans += nums[i][1] - nums[i][0] + 1;
                maxLast = max(maxLast, nums[i][1]);
                // cout << ans << " ";
            }
        }
        return ans;
    }
};


int main() {
    
    return 0;
}