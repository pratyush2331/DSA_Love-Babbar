// 2038. Remove Colored Pieces if Both Neighbors are the Same Color
// LeetCode : https://leetcode.com/problems/remove-colored-pieces-if-both-neighbors-are-the-same-color/

#include<bits/stdc++.h>

using namespace std;


/*
TC : O(n)
SC : O(1)
*/
class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        int aliceChance = 0, bobChance = 0;
        int a = 0, b = 0;
        for(int i = 0; i < n; i++) {
            if(colors[i] == 'A') {
                a++;
                if(a >= 3) aliceChance++;
            }
            else {
                a = 0;
            }
            if(colors[i] == 'B') {
                b++;
                if(b >= 3) bobChance++;
            }
            else {
                b = 0;
            }
        }
        return aliceChance > bobChance;
    }
};


int main() {
    

    return 0;
}