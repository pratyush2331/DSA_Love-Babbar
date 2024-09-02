// 3274. Check if Two Chessboard Squares Have the Same Color
// LeetCode : https://leetcode.com/problems/check-if-two-chessboard-squares-have-the-same-color/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkTwoChessboards(string c1, string c2) {
        bool ans = abs(c1[0] - c2[0])&1 ? 0 : 1;
        ans = abs(c1[1] - c2[1])&1 ? !ans : ans;
        return ans;
    }
};


int main() {

    return 0;
}