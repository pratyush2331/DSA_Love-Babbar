// 118. Pascal's Triangle
// Leetcode: https://leetcode.com/problems/pascals-triangle/

/*
TC : O(n^2)
SC : O(n^2) including output
     O(n) auxiliary space if counting the temporary row
     O(1) extra space if output construction is excluded
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle; // to store Pascal's triangle; SC:O(n^2)
        for(int i = 0; i < numRows; i++) { // populate each row; TC:O(n^2)
            vector<int> row(i+1); // SC:O(n)
            row[0] = 1;
            for(int j = 1; j < i; j++) { // populate non-boundary cells [1,i-1]
                row[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
            if(i) row[i] = 1; // add 1 in the end
            triangle.push_back(row); // push current row to pascal's triangle
        }
        return triangle;
    }
};