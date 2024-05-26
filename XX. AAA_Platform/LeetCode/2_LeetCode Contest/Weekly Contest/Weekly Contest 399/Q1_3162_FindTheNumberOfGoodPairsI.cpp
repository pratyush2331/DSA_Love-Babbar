// 3162. Find the Number of Good Pairs I
// LeetCode : https://leetcode.com/problems/find-the-number-of-good-pairs-i/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        int cnt = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(nums1[i]%(k*nums2[j]) == 0) cnt++;
            }
        }
        return cnt;
    }
};


int main() {
    
    return 0;
}