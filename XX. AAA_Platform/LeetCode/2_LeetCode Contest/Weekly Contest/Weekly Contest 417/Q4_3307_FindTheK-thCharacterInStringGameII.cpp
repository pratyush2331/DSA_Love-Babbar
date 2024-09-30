// 3307. Find the K-th Character in String Game II
// LeetCode : https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii

#include<bits/stdc++.h>
using namespace std;


using ll = long long;
class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        ll len = 1;
        ll idx;
        for(idx = 0; idx < k; idx++) {
            len <<= 1;
            if(len >= k) break; // we got the last operations idx
        }
        ll shift = 0;
        for(ll i = idx; i >= 0; i--) {
            if(k > len/2) {
                if(operations[i] == 1) shift++;
                k -= len/2;
            }
            len >>= 1;
        }
        return 'a' + (shift%26);
    }
};


int main() {

    return 0;
}