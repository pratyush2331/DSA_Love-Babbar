// Dynamic allocation of 2D array

/*
input :
3 3
1 2 3 4 5 6 7 8 9

output :
1 2 3 
4 5 6 
7 8 9 
*/

#include<iostream>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    // matrix creation
    int** arr = new int* [row];
    for(int i = 0; i < row; i++) {
        arr[i] = new int [col];
    }

    // taking input
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cin >> arr[i][j];
        }
    }

    // printing matrix
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // releasing memory
    for(int i = 0; i < row; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    
    return 0;
}