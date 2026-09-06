// 31. Next Permutation
// LeetCode : https://leetcode.com/problems/next-permutation/

#include<bits/stdc++.h>
using namespace std;

// method-1
/*
TC : O(3n)
SC : O(1)
*/

/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int min_index = -1; // to store min_index pivot, where nums[min_index] < right_val while iterating R->L

        for(int i = n-2; i >= 0; i--) { // iterating R->L; TC:O(n)
            if(nums[i] < nums[i+1]) { // finding min_index pivot
                min_index = i; // store it
                break;
            }
        }

        if(min_index != -1) { // if we found min_index pivot, then find the successor (next_smallest_val > pivot_val) [n-1, min_index+1] while iterating R->L
            for(int i = n-1; i > min_index; i--) { // iterate R->L [n-1, min_index+1]; TC:O(n)
                if(nums[i] > nums[min_index]) { // check for val > nums[min_index]
                    swap(nums[i], nums[min_index]); // swap(val, nums[min_index])
                    break;
                }
            }
        }

        reverse(nums.begin() + min_index + 1, nums.end()); // reverse descending_suffix [min_index + 1, n-1]; TC:O(n)
    }
};




// method-2 : using STL
/*
class Solution {
    public:
    void nextPermutation(vector<int>& nums) {
        next_permutation(nums.begin(), nums.end());
    }
};
*/

int main() {
    
    return 0;
}