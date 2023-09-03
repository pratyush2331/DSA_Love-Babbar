// 2841. Maximum Sum of Almost Unique Subarray
// LeetCOde : https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/

// Topics : sliding-window, unordered_map

#include<iostream>
using namespace std;


class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long maxi = 0;
        long long sum = 0;
        unordered_map<int, int> window;
        
        for(int i = 0; i < k; i++) {
            sum += nums[i];
            window[nums[i]]++;
        }
        
        if(window.size() >= m) {
            maxi = max(maxi, sum);
        }
        
        for(int i = k; i < nums.size(); i++) {
            // Remove the leftmost element from the window
            int leftElement = nums[i - k];
            sum -= leftElement;
            if(window[leftElement] > 1) {
                window[leftElement]--;
            }
            else {
                window.erase(leftElement);
            }
            
            // Add the current element to the window
            sum += nums[i];
            window[nums[i]]++;
            
            if(window.size() >= m) {
                maxi = max(maxi, sum);
            }
        }
        
        return maxi;
    }
};



int main() {
    
    return 0;
}