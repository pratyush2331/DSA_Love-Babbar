// 2799. Count Complete Subarrays in an Array
// LeetCode : https://leetcode.com/problems/count-complete-subarrays-in-an-array/

// Topic : set/unordered_set

#include<iostream>
using namespace std;


class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> uniqueElements;
        for(int i = 0; i < nums.size(); i++) {
            uniqueElements.insert(nums[i]);
        }
        
        int count = 0;
        for(int i = 0 ; i < nums.size(); i++) {
            unordered_set<int> temp;
            for(int j = i; j < nums.size(); j++) {
                temp.insert(nums[j]);
                if(uniqueElements.size() == temp.size()) {
                    count++;
                }
            }
        }
        return count;
    }
};


int main() {
    
    return 0;
}