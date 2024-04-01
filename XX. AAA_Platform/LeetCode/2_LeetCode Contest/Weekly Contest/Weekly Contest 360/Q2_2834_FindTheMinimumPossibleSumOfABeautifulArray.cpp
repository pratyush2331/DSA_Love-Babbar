// 2834. Find the Minimum Possible Sum of a Beautiful Array
// LeetCode : https://leetcode.com/problems/find-the-minimum-possible-sum-of-a-beautiful-array/

#include<iostream>
using namespace std;


class Solution {
public:
    long long minimumPossibleSum(int n, int target) {
        unordered_map<int, bool> mp;
        int num = 1;
        for(int i = 0; i < n; i++) {
            while(mp.find(target - num) != mp.end()) {
                num++;
            }
            mp[num] = 1;
            // cout << num << " ";
            num++;
        }
        // cout << endl;
        
        long long ans = 0;
        for(auto ele : mp) {
            // cout << ele.first << " ";
            ans += ele.first;
        }
        // cout << endl;
        return ans;
    }
};


int main() {
    
    return 0;
}