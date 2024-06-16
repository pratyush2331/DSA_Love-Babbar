// 3185. Count Pairs That Form a Complete Day II
// LeetCode : https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        long long cnt = 0;
        unordered_map<int, int> mp; // {mod value, freq}
        
        for(int i = 0; i < n; i++) {
            int x = hours[i] % 24;
            int complement = (x == 0) ? 0 : 24 - x;
            cnt += mp[complement];   
            mp[x]++;
        }
        
        return cnt;
    }
};


int main() {
    
    return 0;
}