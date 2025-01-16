// 

#include<bits/stdc++.h>
using namespace std;


// one liner
/*
TC : O(m+n)
SC : O(1)
*/
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        return ((nums2.size() & 1) ? accumulate(nums1.begin(), nums1.end(), 0, bit_xor<int>()) : 0) ^ ((nums1.size() & 1) ? accumulate(nums2.begin(), nums2.end(), 0, bit_xor<int>()) : 0);
    }
};


// readable
/*
TC : O(m+n)
SC : O(1)
*/
class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        if(n2&1) {
            for(int& ele : nums1) {
                ans ^= ele;
            }
        }
        if(n1&1) {
            for(int& ele : nums2) {
                ans ^= ele;
            }
        }
        return ans;
    }
};


int main() {
    
    return 0;
}