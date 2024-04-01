// Search in a row-column sorted Matrix
// GFG : https://www.geeksforgeeks.org/problems/search-in-a-matrix-1587115621/1

#include<bits/stdc++.h>

using namespace std;


// Optimal Approach
/*
TC : O(2*n) = O(n)
SC : O(1)
*/
class Solution {
    public:
    //Function to search a given number in row-column sorted matrix.
    bool search(vector<vector<int> > matrix, int n, int m, int x) {
        int i = 0, j = m-1;
        while(i < n & j >= 0) {
            if(matrix[i][j] == x) return 1;
            else if(x > matrix[i][j]) i++;
            else j--;
        }
        
        return 0;
    }
};


int main() {
    

    return 0;
}