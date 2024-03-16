// 3079. Find the Sum of Encrypted Integers
// LeetCode : https://leetcode.com/problems/find-the-sum-of-encrypted-integers

#include<bits/stdc++.h>

using namespace std;


/*
TC : O(n * len(digit))
SC : O(1)
*/
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(auto ele : nums) {
            int cnt = 0;
            int maxi = 0;
            while(ele) {
                maxi = max(maxi,ele%10);
                ele = ele/10;
                cnt++;
            }
            int i = 0;
            while(i < cnt) {
                ans += maxi * pow(10,i);
                i++;
            }
        }
        return ans;
    }
};


int main() {
    

    return 0;
}