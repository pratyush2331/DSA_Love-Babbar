// LeetCode-240 : Search a 2D Matrix II
/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Input: 
Enter rows & cols : 5 5
Enter elements in a matrix : 
1 4 7 11 15 
2 5 8 12 19
3 6 9 16 22
10 13 14 17 24
18 21 23 26 30
Enter target : 5

Output: 
5 is present or not : 1
---------------------------------------------------
Input: 
Enter rows & cols : 5 5
Enter elements in a matrix : 
1 4 7 11 15 
2 5 8 12 19
3 6 9 16 22
10 13 14 17 24
18 21 23 26 30
Enter target : 20

Output: 
5 is present or not : 0
*/

#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    
    int rowIndex = 0;
    int colIndex = nCols - 1;
    
    // Binary Search - minimizing the search space
    while(rowIndex < nRows && colIndex >= 0) {
        int ele = matrix[rowIndex][colIndex];
        
        if(target == ele) {
            return 1;
        }
        
        if(target > ele) {
            rowIndex++;
        }
        else {
            colIndex--;
        }
    }
    
    return 0;
}

int main() {
    vector<vector<int>> matrix;

    int m, n;
    cout << "Enter rows & cols : ";
    cin>>m>>n;

    cout << "Enter elements in a matrix : " << endl;
    for(int i = 0; i < m; i++) {
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            int data;
            cin>>data;
            temp.push_back(data);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    int target;
    cout << "Enter target : ";
    cin >> target;

    cout << target << " is present or not : " << searchMatrix(matrix, target) << endl;

    return 0;
}