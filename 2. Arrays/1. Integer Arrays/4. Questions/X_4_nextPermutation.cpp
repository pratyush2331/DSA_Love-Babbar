// 31. Next Permutation
// LeetCode : https://leetcode.com/problems/next-permutation/

#include<iostream>
using namespace std;

/*
TC : O(3n)
SC : O(1)
*/

class Solution {
    private:
    void reverse(vector<int>& nums, int s, int e) {
        while(s < e) {
            swap(nums[s++], nums[e--]);
        }
    }
    
    public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        int peak = INT_MIN;
        int index = -1;
        for(int i = n-2; i >= 0; i--) { // TC: O(n)
            if(nums[i] < nums[i+1]) {
                peak = nums[i];
                index = i;
                break;
            }
        }
        
        if(index != -1) {
            for(int i = n-1; i > index; i--){ // TC: O(n)
                if(nums[i] > nums[index]){
                    swap(nums[i], nums[index]);
                    break;
                }
            }
            
        }

        reverse(nums, index+1, n-1); // TC: O(n)
    }
};

int main() {
    
    return 0;
}