// Coding Ninjas : Spiral Print
/*
Sample Input 1:
1
4 4 
1 2 3 4 
5 6 7 8 
9 10 11 12 
13 14 15 16

Sample Output 1:
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
--------------------------------------------------------------------------
Sample Input 2:
2
3 3 
1 2 3 
4 5 6 
7 8 9
3 1
10
20
30

Sample Output 2:
1 2 3 6 9 8 7 4 5
10 20 30
*/

#include <iostream>
using namespace std;

void spiralPrint(int **input, int nRows, int nCols) {
    int rs = 0, re = nRows-1;
    int cs = 0, ce = nCols-1;

    int total = nRows*nCols;
    int count = 0; // for counting total no. of elements, we printed
    
    while(rs <= re && cs <= ce) {
        for(int i = cs; i <= ce && count < total; i++) {
            cout << input[rs][i] << " ";
            count++;
        }
        rs++;
        for(int i = rs; i <= re && count < total; i++) {
            cout << input[i][ce] << " ";
            count++;
        }
        ce--;
        for(int i = ce; i >= cs && count < total; i--) {
            cout << input[re][i] << " ";
            count++;
        }
        re--;
        for(int i = re; i >= rs && count < total; i--) {
            cout << input[i][cs] << " ";
            count++;
        }
        cs++;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int row, col;
        cin >> row >> col;
        int **matrix = new int *[row];

        for (int i = 0; i < row; i++)
        {
            matrix[i] = new int[col];
            for (int j = 0; j < col; j++)
            {
                cin >> matrix[i][j];
            }
        }
        spiralPrint(matrix, row, col);

        for (int i = 0; i < row; ++i)
        {
            delete[] matrix[i];
        }
        delete[] matrix;

        cout << endl;
    }
}