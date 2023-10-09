// LeetCode-48 : Rotate Image
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

// Method - 1
/*
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    
    // changing symmetrically from middle row
    for(int i = 0; i < n/2; i++) {
        for(int j = 0; j < n; j++) {
            swap(matrix[i][j], matrix[n-1-i][j]);
        }
    }
    
    // taking transpose
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}
*/

// Method - 2
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < (n + 1) / 2; i ++) {
        for (int j = 0; j < n / 2; j++) {
            int temp = matrix[n - 1 - j][i];
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
            matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 -i];
            matrix[j][n - 1 - i] = matrix[i][j];
            matrix[i][j] = temp;
        }
    }
}

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