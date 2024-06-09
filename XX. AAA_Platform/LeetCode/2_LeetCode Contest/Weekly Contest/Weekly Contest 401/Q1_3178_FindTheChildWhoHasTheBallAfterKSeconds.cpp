// 3178. Find the Child Who Has the Ball After K Seconds
// LeetCode : https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numberOfChild(int n, int k) {
        int ans = 0;
        bool flag = 0;
        while(k--) {
            if(flag == 0) ans += 1;
            else ans -= 1;
            if(ans == n-1) flag = 1;
            if(ans == 0) flag = 0;
        }
        return ans;
    }
};


int main() {
    
    return 0;
}