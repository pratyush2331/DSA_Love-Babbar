// 3160. Find the Number of Distinct Colors Among the Balls
// leetCode : https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> ans;
        unordered_map<int, set<int>> colorToBall;
        unordered_map<int, int> ballToColor;
        for(auto qr : queries) {
            int ball = qr[0];
            int color = qr[1];
            // Check if the ball is already associated with a color
            if(ballToColor.find(ball) != ballToColor.end()) {
                int oldColor = ballToColor[ball];
                // Remove the ball from the set of its old color
                colorToBall[oldColor].erase(ball);
                // If the set becomes empty, remove the color entry
                if(colorToBall[oldColor].empty()) {
                    colorToBall.erase(oldColor);
                }
            }
            ballToColor[ball] = color;
            colorToBall[color].insert(ball);
            ans.push_back(colorToBall.size());
        }
        return ans;
    }
};


int main() {
    
    return 0;
}