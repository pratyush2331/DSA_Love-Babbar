// 3068. Find the Maximum Sum of Node Values
// LeetCode : https://leetcode.com/problems/find-the-maximum-sum-of-node-values/

#include<bits/stdc++.h>

using namespace std;


/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum = 0, sacrifice = 1e9;
        int cnt = 0;

        for(auto ele : nums) {
            if(ele < (ele^k)) {
                sum += (ele^k);
                sacrifice = min(sacrifice, (long long)(ele^k) - ele);
                cnt++;
            }
            else {
                sum += ele;
                sacrifice = min(sacrifice, (long long)ele - (ele^k));
            }
        }

        if(cnt & 1) return (sum - sacrifice);
        else return sum;

        return sum;
    }
};


int main() {
    

    return 0;
}