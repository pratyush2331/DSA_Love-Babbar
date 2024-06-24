// 3194. Minimum Average of Smallest and Largest Elements
// LeetCode : https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/

#include<bits/stdc++.h>
using namespace std;


// method-1 : using 2 pointers
/*
TC : O(n.logn)
SC : O(1)
*/
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double mini = INT_MAX;
        sort(nums.begin(), nums.end());
        int s = 0, e = nums.size()-1;
        while(s < e) {
            double avg = (nums[s++] + nums[e--]) / 2.0;
            mini = min(mini, avg);
        }
        return mini;
    }
};


// method-0 : using heap
/*
TC : O(n.logn)
SC : O(n)
*/
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        priority_queue<float> maxHeap;
        priority_queue<float, vector<float>, greater<float>> minHeap;
        for(auto ele : nums) {
            minHeap.push(ele);
            maxHeap.push(ele);
        }
        float minEle, maxEle;
        int n = nums.size();
        priority_queue<float, vector<float>, greater<float>> ans;
        for(int i = 0; i < n/2; i++) {
            minEle = minHeap.top();
            minHeap.pop();
            maxEle = maxHeap.top();
            maxHeap.pop();
            float newEle = (float)(minEle + maxEle)/2.0;
            ans.push(newEle);
        }
        
        return ans.top();
    }
};


int main() {
    
    return 0;
}