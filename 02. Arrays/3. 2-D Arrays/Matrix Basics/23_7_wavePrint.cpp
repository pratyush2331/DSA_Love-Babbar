// Coding Ninjas : Wave Print
// For a given two-dimensional integer array/list of size (N x M), print the array/list in a sine wave order, i.e, print the first column top to bottom, next column bottom to top and so on.
/*
Sample Input 1:
1
3 4 
1  2  3  4 
5  6  7  8 
9 10 11 12

Sample Output 1:
1 5 9 10 6 2 3 7 11 12 8 4
-----------------------------------------------------------------

Sample Input 2:
2
5 3 
1 2 3 
4 5 6 
7 8 9 
10 11 12 
13 14 15
3 3
10 20 30 
40 50 60
70 80 90

Sample Output 2:
1 4 7 10 13 14 11 8 5 2 3 6 9 12 15 
10 40 70 80 50 20 30 60 90 
*/

#include<iostream>
using namespace std;

void wavePrint(int **input, int nRows, int mCols) {
    for(int j = 0; j < mCols; j++) {
        if(j & 1) { // for odd cols
            for(int i = nRows-1; i >= 0; i--) {
                cout << input[i][j] << " ";
            }
        }
        else {      // for even cols
            for(int i = 0; i < nRows; i++) {
                cout << input[i][j] << " ";
            }
        }
    }
    cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int row, col;
		cin >> row >> col;
		int **input = new int *[row];
		for (int i = 0; i < row; i++)
		{
			input[i] = new int[col];
			for (int j = 0; j < col; j++)
			{
				cin >> input[i][j];
			}
		}
		wavePrint(input, row, col);
		cout << endl;
	}
}