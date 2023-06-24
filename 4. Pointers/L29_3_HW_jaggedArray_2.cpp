// 2D array of variable column

/*
input :
5                                      <--- number of rows
2 1 4 3 5                              <--- column array
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15    <--- matrix input

output :
1 2 
3 
4 5 6 7 
8 9 10
11 12 13 14 15
*/

#include<iostream>
using namespace std;

int main() {
    int row;
    cin >> row;

    // taking column array
    int* col = new int [row];
    for(int i = 0; i < row; i++) {
        cin >> col[i];
    }

    // creating matrix
    int** arr = new int* [row];
    for(int i = 0; i < row; i++) {
        arr[i] = new int [col[i]];
    }

    // taking input
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col[i]; j++) {
            cin >> arr[i][j];
        }
    }

    // printing matrix
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // releasing memory
    for(int i = 0 ; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}