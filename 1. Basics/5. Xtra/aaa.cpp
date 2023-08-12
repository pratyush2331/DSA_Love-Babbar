// Coding Ninjas - 1 : Print 2D Array
/*
#include<iostream>
using namespace std;

void print2DArray(int **matrix, int nRows, int nCols) {
    for(int i = 0; i < nRows; i++) {
        for(int k = nRows-i; k >= 1; k--) {
            for(int j = 0; j < nCols; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
}

int main() {
    int nRows, nCols;
    cin >> nRows >> nCols;
    int** matrix = new int* [nRows];

    for (int i = 0; i < nRows; i++)
    {
        matrix[i] = new int [nCols];
        for (int j = 0; j < nCols; j++)
        {
            cin >> matrix[i][j];
        }
    }

    print2DArray(matrix, nRows, nCols);

    for (int i = 0; i < nRows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;

    cout << endl;
    
    return 0;
}
*/

// -------------------------------------------------------------------------------------------------------------------------------------------

// Coding Ninjas - 2 : Minimum Length Word
/*
sample i/p:
this is test string
sample o/p:
is
*/

/*
#include<iostream>
#include<cstring>
using namespace std;

string minLenWord(string s) {
    int startIndex;
    int count = INT_MAX;
    for(int i = 0; i < s.length(); i++) {
        int j = i+1;
        while(s[j] != ' ' && s[j] != '\0') {
            j++;
        }
        if(j-i < count) {
            startIndex = i;
            count = j-i;
        }
        i = j;
    }
    return s.substr(startIndex, count);
}

int main() {
    string s;
    getline(cin, s);

    cout << minLenWord(s) << endl;

    return 0;
}
*/
