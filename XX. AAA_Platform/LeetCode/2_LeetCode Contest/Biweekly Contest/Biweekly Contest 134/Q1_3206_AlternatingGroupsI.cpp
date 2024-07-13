// 3206. Alternating Groups I
// LeetCode : https://leetcode.com/problems/alternating-groups-i

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            bool isAlternating = true;
            for (int j = 0; j < k; j++) {
                int currentIndex = (i + j) % n;
                int nextIndex = (i + j + 1) % n;
                if (colors[currentIndex] == colors[nextIndex]) {
                    isAlternating = false;
                    break;
                }
            }
            if (isAlternating) {
                count++;
            }
        }
        
        return count;
    }
};


int main() {
    
    return 0;
}