// 3226. Number of Bit Changes to Make Two Integers Equal
// LeetCode : https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int minChanges(int n, int k) {
        int cnt = 0;
        while(n) {
            if((n&1) && !(k&1)) cnt++;
            else if(!(n&1) && (k&1)) return -1;
            n = n >> 1;
            k = k >> 1;
        }
        if(k) return -1;
        return cnt;
    }
};


int main() {
    
    return 0;
}