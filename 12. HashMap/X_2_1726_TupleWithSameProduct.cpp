// 1726. Tuple with Same Product
// LeetCode : https://leetcode.com/problems/tuple-with-same-product/

#include<bits/stdc++.h>
using namespace std;


// using HashMap
/*
TC : O(n^2)
SC : O(n^2)
*/
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> mp; // {prod, freq}
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i+1; j < nums.size(); j++) {
                mp[nums[i] * nums[j]]++;
            }
        }
        int cnt = 0;
        for(auto& ele : mp) {
            cnt += (ele.second >= 2) ? (ele.second * (ele.second-1)) >> 1 : 0;
        }
        return cnt*8;
    }
};


int main() {
    
    return 0;
}