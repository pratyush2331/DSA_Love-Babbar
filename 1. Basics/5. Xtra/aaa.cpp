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
    int startIndex, endIndex;
    int count = INT_MAX;
    for(int i = 0; i < s.length(); i++) {
        int j = i+1;
        while(s[j] != ' ' && s[j] != '\0') {
            j++;
        }
        if(j-i < count) {
            startIndex = i;
            endIndex = j;
            count = j-i;
            // cout << startIndex << " " << endIndex << endl;
        }
        i = j;
    }

    return s.substr(startIndex, endIndex-startIndex);
}

int main() {
    string s;
    getline(cin, s);

    cout << minLenWord(s) << endl;

    return 0;
}
*/

// --------------------------------------------------------------------------------------------------------------------------------------------

// Coding Ninjas - 3 : Leaders in array
/*
6
3 12 34 2 0 -1

34 2 0 -1

-------------------------------------------------------

5
13 17 5 4 6

17 6
*/

#include<iostream>
using namespace std;

void leadersInArray(int arr[], int len) {
    int save[len];
    int j=0;

    int largest=INT_MIN;
    //largest contains the maximum value of leading array.
    for(int i=len-1;i>=0;i--) {
        if(arr[i]>=largest){
            // if element at current index is greater than largest then put it in array and make it largest;
            largest=arr[i];
            save[j++]=largest;
        }
    }
    for(int i=j-1;i>=0;i--) {
        // Print the array in reverse order...
        cout<<save[i] << " ";
    }
}

int main() {
    int arr[100];

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    leadersInArray(arr, n);
    
    return 0;
}
