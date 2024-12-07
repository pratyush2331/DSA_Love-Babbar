// 1760. Minimum Limit of Balls in a Bag
// LeetCode : https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

#include<bits/stdc++.h>
using namespace std;


// used binary search on answer
/*
TC : O(n . log(max_element_in_nums))
SC : O(1)
*/
class Solution {
    bool isValid(vector<int>& nums, int maxOperations, int maxSize) {
        for(int ele : nums) {
            maxOperations -= ceil((double)ele / maxSize) - 1;
            if(maxOperations < 0) return 0;
        }
        return 1;
    }

public:
    Solution() {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int s = 1, e = *max_element(nums.begin(), nums.end());

        int ans = e;
        while(s <= e) {
            int mid = s + (e-s)/2;

            if(isValid(nums, maxOperations, mid)) {
                ans = mid;
                e = mid - 1;
            }
            else {
                s = mid+1;
            }
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