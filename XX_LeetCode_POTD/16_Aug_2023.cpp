// 239. Sliding Window Maximum
// LeetCode : https://leetcode.com/problems/sliding-window-maximum/

#include<iostream>
using namespace std;


class Solution {
    // method-1 : priority_queue
    /*
    TC : O(n.logn)
    SC : O(n)
    */
    // /*
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        // max heap
        priority_queue<pair<int,int>> pq;

        for(int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);

        for(int i = k; i < nums.size(); i++) {
            while(!pq.empty() && pq.top().second <= (i-k)) {
                pq.pop();
            }
            pq.push({nums[i], i});
            ans.push_back(pq.top().first);
        }

        return ans;
    }
    // */



    // method-0 : 2 for loops
    /*
    TC : O(n*k)
    SC : O(1)
    */
    /*
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        
        for(int i = 0; i <= nums.size()-k; i++) {
            int maxi = INT_MIN;
            for(int j = 0; j < k; j++) {
                maxi = max(maxi, nums[i+j]);
            }
            ans.push_back(maxi);
        }

        return ans;
    }
    */
};


int main() {
    
    return 0;
}