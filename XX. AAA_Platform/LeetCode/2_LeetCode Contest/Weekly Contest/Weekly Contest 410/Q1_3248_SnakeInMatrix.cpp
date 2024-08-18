// 3248. Snake in Matrix
// LeetCode : https://leetcode.com/problems/snake-in-matrix/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int i = 0, j = 0;
        for(auto cd : commands) {
            if(cd == "UP") i--;
            else if(cd == "DOWN") i++;
            else if(cd == "LEFT") j--;
            else if(cd == "RIGHT") j++;
        }

        return (i*n) + j;
    }
};


int main() {
        
    return 0;
}