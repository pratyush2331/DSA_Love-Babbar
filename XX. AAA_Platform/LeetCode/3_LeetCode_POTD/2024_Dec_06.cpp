// 2337. Move Pieces to Obtain a String
// LeetCode : https://leetcode.com/problems/move-pieces-to-obtain-a-string/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool canChange(string start, string target) {
        int left = 0, right = 0;
        for(int i = 0; i < start.length(); i++) {
            if(left < 0 || right < 0) return 0;
            if(left && right) return 0;

            if(start[i] == '_' && target[i] == 'L') left++;
            else if(start[i] == 'L' && target[i] == '_') left--;
            else if(start[i] == 'R' && target[i] == '_') right++;
            else if(start[i] == '_' && target[i] == 'R') right--;
            else if(start[i] == 'R' && target[i] == 'L') return 0;
            else if(start[i] == 'L' && target[i] == 'R') return 0;
            else if(start[i] == target[i] && start[i] == 'L' && right) return 0;
            else if(start[i] == target[i] && start[i] == 'R' && left) return 0;
        }
        return (!left && !right);
    }
};


int main() {
    
    return 0;
}