// 3394. Check if Grid can be Cut into Sections
// LeetCode : https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/

#include<bits/stdc++.h>
using namespace std;


// method-1 : using Line Sweep logic
/*
TC : O(n.logn)
SC : O(n)
*/
class Solution {
    // Check if valid cuts can be made in a specific dimension
    bool checkCuts(vector<vector<int>>& rectangles, int dim) {
        int gapCount = 0;

        // Sort rectangles by their starting coordinate in the given dimension
        sort(rectangles.begin(), rectangles.end(),
             [dim](const vector<int>& a, const vector<int>& b) {
                 return a[dim] < b[dim];
             });

        // Track the furthest ending coordinate seen so far
        int furthestEnd = rectangles[0][dim + 2];

        for (size_t i = 1; i < rectangles.size(); i++) {
            vector<int>& rect = rectangles[i];

            // If current rectangle starts after the furthest end we've seen,
            // we found a gap where a cut can be made
            if (furthestEnd <= rect[dim]) {
                gapCount++;
            }

            // Update the furthest ending coordinate
            furthestEnd = max(furthestEnd, rect[dim + 2]);
        }

        // We need at least 2 gaps to create 3 sections
        return gapCount >= 2;
    }

public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // Try both horizontal and vertical cuts
        return checkCuts(rectangles, 0) || checkCuts(rectangles, 1);
    }
};


// method-0 : using merge intervals logic
/*
TC : O(n.logn)
SC : O(n)
*/
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        // extracting x and y coordinates
        vector<vector<int>> x_cords(rectangles.size(), vector<int>(2)), y_cords(rectangles.size(), vector<int>(2)); // SC:O(2n)
        for(int i = 0; i < rectangles.size(); i++) { // TC:O(n)
            x_cords[i][0] = rectangles[i][0];
            x_cords[i][1] = rectangles[i][2];
            y_cords[i][0] = rectangles[i][1];
            y_cords[i][1] = rectangles[i][3];
        }

        // looking in X direction
        sort(x_cords.begin(), x_cords.end()); // TC:O(n.logn)
        int x_start = x_cords[0][0], x_end = x_cords[0][1];
        int cnt = 0;
        for(int i = 1; i < x_cords.size(); i++) { // TC:O(n)
            if(x_cords[i][0] >= x_end) cnt++;
            if(cnt == 2) return 1;
            x_end = max(x_end, x_cords[i][1]);
        }

        // looking in Y direction
        sort(y_cords.begin(), y_cords.end()); // TC:O(n.logn)
        int y_start = y_cords[0][0], y_end = y_cords[0][1];
        cnt = 0;
        for(int i = 1; i < y_cords.size(); i++) { // TC:O(n)
            if(y_cords[i][0] >= y_end) cnt++;
            if(cnt == 2) return 1;
            y_end = max(y_end, y_cords[i][1]);
        }

        // valid cut isn't not possible
        return 0;
    }
};


int main() {
    
    return 0;
}