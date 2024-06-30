// 3200. Maximum Height of a Triangle
// LeetCode : https://leetcode.com/problems/maximum-height-of-a-triangle/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int maxHeightOfTriangle(int red1, int blue1) {
        int blue = blue1;
        int red = red1;
        int cnt = 1;
        bool flipped = false;
        while (true) {
            if (!flipped && blue >= cnt) {
                blue -= cnt;
            }
            else if (flipped && red >= cnt) {
                red -= cnt;
            }
            else {
                break;
            }
            cnt++;
            flipped = !flipped;
        }
        int ans = max(0, cnt-1);
        blue = blue1;
        red = red1;
        swap(blue, red);
        cnt = 1;
        flipped = false;
        while (true) {
            if (!flipped && blue >= cnt) {
                blue -= cnt;
            }
            else if (flipped && red >= cnt) {
                red -= cnt;
            }
            else {
                break;
            }
            cnt++;
            flipped = !flipped;
        }
        return max(ans, cnt-1);
    }
};


int main() {
    
    return 0;
}