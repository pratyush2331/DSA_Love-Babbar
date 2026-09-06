// 48. Rotate Image
// LeetCode : https://leetcode.com/problems/rotate-image/
/*
sample i/p - 1:
1 2 3
4 5 6
7 8 9

sample o/p - 1:
7 4 1 
8 5 2 
9 6 3 
-----------------------------------------------------------
sample i/p - 2:
1 2 3 4
5 6 7 8
9 10 11 12
13 14 15 16

sample o/p - 2:
13 9 5 1 
14 10 6 2 
15 11 7 3 
16 12 8 4 
*/

#include<iostream>
#include<vector>

using namespace std;

/*
TC : O(n^2)
SC : O(1)
*/
// method-0 : transpose + reverse approach
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // 1. transpose
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // 2. reverse rows
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n/2; j++) {
                swap(matrix[i][j], matrix[i][n-j-1]);
            }
        }
    }
};

// method-1 : quadrant rotation approach
/*
[(0,0), (0,1), (0,2), (0,3)]
[(1,0), (1,1), (1,2), (1,3)]
[(2,0), (2,1), (2,2), (2,3)]
[(3,0), (3,1), (3,2), (3,3)]

(0,1) --> (2,0)
(i,j) --> (n-j-1,i)

(2,0) --> (3,2)
(n-j-1,i) --> (n-i-1,n-j-1)

(3,2) --> (1,3)
(n-i-1,n-j-1) --> (j,n-i-1)

(1,3) --> (0,1)
(j,n-i-1) --> (i,j) {temp}
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++) {
            for(int j = 0; j < (n+1)/2; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
    }
};

// method-2 : 4-way cyclic rotation approach
/*
[(0,0), (0,1), (0,2), (0,3)]
[(1,0), (1,1), (1,2), (1,3)]
[(2,0), (2,1), (2,2), (2,3)]
[(3,0), (3,1), (3,2), (3,3)]

(0,1) --> (2,0)
(i,j) --> (n-j-1,i)

(2,0) --> (3,2)
(n-j-1,i) --> (n-i-1,n-j-1)

(3,2) --> (1,3)
(n-i-1,n-j-1) --> (j,n-i-1)

(1,3) --> (0,1)
(j,n-i-1) --> (i,j) {temp}
*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i = 0; i < n/2; i++) {
            for(int j = i; j < n-i-1; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-j-1][i];
                matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
                matrix[j][n-i-1] = temp;
            }
        }
    }
};

void printArray(vector<vector<int>> matrix) {
    int nRows = matrix.size();
    int nCols = matrix[0].size();

    for(int i = 0; i < nRows; i++) {
        for(int j = 0; j < nCols; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix;

    int n;
    cout << "Enter size for square matrix : ";
    cin >> n;

    cout << "Enter elements in a matrix : " << endl;
    for(int i = 0; i < n; i++) {
        vector<int> temp;
        for(int j = 0; j < n; j++) {
            int data;
            cin >> data;
            temp.push_back(data);
        }
        matrix.push_back(temp);
        temp.clear();
    }

    rotate(matrix);

    printArray(matrix);
    
    return 0;
}