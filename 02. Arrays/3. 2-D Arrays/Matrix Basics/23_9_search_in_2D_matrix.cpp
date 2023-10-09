// LeetCode-74 : Search a 2D Matrix
/*
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Input: 
Enter rows & cols : 3 4
Enter elements in a matrix : 
1 3 5 7
10 11 16 20
23 30 34 60
Enter target : 13

Output: 
13 is present or not : 0
----------------------------------------------------
Input: 
Enter rows & cols : 3 4
Enter elements in a matrix : 
1 3 5 7
10 11 16 20
23 30 34 60
Enter target : 3

Output: 
3 is present or not : 1
*/

#include<iostream>
#include<vector>

using namespace std;

// TC : O( log(n+m) )
bool searchMatrix(vector<vector<int>>& matrix, int target) {    
    int nRows = matrix.size();
    int nCols = matrix[0].size();
    
    int s = 0, e = nRows*nCols - 1;
    int mid = s + (e-s)/2;
    
    // Binary Search
    while(s <= e) {
        int ele = matrix[mid/nCols][mid%nCols];
        
        if(target == ele) {
            return 1;
        }
        
        if(target > ele) {
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
        
        mid = s + (e-s)/2;
    }
    
    return 0; // ele mila hi nhi !
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