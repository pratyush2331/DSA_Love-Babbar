// 42. Trapping Rain Water
// LeetCode : https://leetcode.com/problems/trapping-rain-water/description/

#include<iostream>
using namespace std;


class Solution {
    public:

    // method-1 : 2 pointer approach
    /*
    TC : O(n)
    SC : O(1)
    */
    // /*
    int trap(vector<int>& height) {
        int trappedWater = 0;
        int maxLeft = 0, maxRight = 0;
        int left = 0, right = height.size()-1;
        while(left < right) {
            if(height[left] <= height[right]) {
                if(height[left] >= maxLeft)
                    maxLeft = height[left];
                else
                    trappedWater += (maxLeft - height[left]);
                left++;
            }
            else {
                if(height[right] >= maxRight)
                    maxRight = height[right];
                else
                    trappedWater += (maxRight - height[right]);
                right--;
            }
        }
        return trappedWater;
    }
    // */



    // method-0 : using 2 additional arrays fro preprocessing
    /*
    TC : O(3n) = O(n)
    SC : O(2n) = O(n)
    */
    /*
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> maxLeft(n), maxRight(n);

        maxLeft[0] = height[0];
        for(int i = 1; i < n; i++) {
            maxLeft[i] = max(height[i], maxLeft[i-1]);
        }

        maxRight[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            maxRight[i] = max(height[i], maxRight[i+1]);
        }

        int trappedWater = 0;
        for(int i = 0; i < n; i++) {
            int water = min(maxLeft[i], maxRight[i]) - height[i];
            if(water >= 0)
                trappedWater += water;
        }

        return trappedWater;
    }
    */
};


int main() {
    
    return 0;
}