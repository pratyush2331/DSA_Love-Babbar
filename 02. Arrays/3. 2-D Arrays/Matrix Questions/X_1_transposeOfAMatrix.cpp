// 867: Transpose Matrix
// LeetCode : https://leetcode.com/problems/transpose-matrix/

/*
NOTE: n may or may not be equal
*/

#include<iostream>
#include<vector>

using namespace std;

// TC: O(n^2), SC: O(n^2)
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    vector<vector<int>> ans(n, vector<int>(m));
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
                ans[j][i] = matrix[i][j];
        }
    }
    
    return ans;
}

void printMatrix(vector<vector<int>> ans, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
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

    vector<vector<int>> ans = transpose(matrix);

    printMatrix(ans, m, n);

    return 0;
}