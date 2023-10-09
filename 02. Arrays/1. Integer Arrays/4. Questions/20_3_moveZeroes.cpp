// 283. Move Zeroes
// Leetcode: https://leetcode.com/problems/move-zeroes/

// Move Zeroes to Right without changing the relative order of non-zeroes element

#include<iostream>
#include<vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i = 0; // pointing to zeroes
    for(int j = 0; j < nums.size(); j++) {
        if(nums[j] != 0) {
            swap(nums[i++], nums[j]);
        }
    }
}

void printArray(vector<int> nums, int n) {
    for(int i =0; i < n; i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> nums;

    int n;
    cin>>n;

    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        nums.push_back(data);
    }

    moveZeroes(nums);

    printArray(nums, n);

    return 0;
}