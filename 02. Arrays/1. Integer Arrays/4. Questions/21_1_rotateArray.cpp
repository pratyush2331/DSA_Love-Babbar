// 189. Rotate Array
// LeetCode : https://leetcode.com/problems/rotate-array/

// Rotate Array by 'k' steps; where K > 0.

/*
Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]

Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
*/

#include<iostream>
#include<vector>
using namespace std;




// BEST APPROACH
/*
TC: O(n)
SC: O(1)
*/

void reverse(vector<int>& nums, int s, int e) {
    while(s < e) {
        swap(nums[s++], nums[e--]);
    }
}

void rotate(vector<int>& nums, int k) {
    int n = nums.size();

    k = k % n;

    reverse(nums, 0, n-1);
    reverse(nums, 0, k-1);
    reverse(nums, k, n-1);

    // ------------OR-----------
    
    // reverse(nums, 0, n-k-1);
    // reverse(nums, n-k, n-1);
    // reverse(nums, 0, n-1);
}




// BRUTE FORCE
/*
TC: O(n)
SC: O(n)
*/

/*
void rotate(vector<int>& nums, int k) {
    int n = nums.size();
    
    vector<int> ans(n);
    
    for(int i = 0; i < n; i++) {
        ans[(i+k)%n] = nums[i]; // kind of mapping
    }
    
    nums = ans;
}
*/




void printArray(vector<int> nums, int n) {
    for(int i = 0; i < n; i++) {
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n, k;
    cin>>n>>k;

    vector<int> nums;

    for(int i = 0; i < n; i++) {
        int data;
        cin>>data;
        nums.push_back(data);
    }

    rotate(nums, k);

    printArray(nums, n);

    return 0;
}