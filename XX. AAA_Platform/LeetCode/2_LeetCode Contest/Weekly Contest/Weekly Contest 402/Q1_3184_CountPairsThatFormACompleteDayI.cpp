// 3184. Count Pairs That Form a Complete Day I
// LeetCode : https://leetcode.com/problems/count-pairs-that-form-a-complete-day-i/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int countCompleteDayPairs(vector<int>& hours) {
        int n = hours.size();
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if((hours[i] + hours[j]) % 24 == 0) cnt++;
            }
        }
        return cnt;
    }
};


int main() {
    
    return 0;
}