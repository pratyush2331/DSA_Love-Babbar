// Jagged Array in C++

/*
input :
5
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14

output :
0 
1 2 
3 4 5 
6 7 8 9 
10 11 12 13 14
*/

#include<iostream>
using namespace std;

int main() {
    int row;
    cin >> row;

    // jagged matrix creation
    int** arr = new int* [row];
    for(int i = 0; i < row; i++) {
        arr[i] = new int [i+1];
    }

    // jagged matrix i/p
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < i+1; j++) {
            cin >> arr[i][j];
        }
    }

    // printing jagged matrix
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < i+1; j++) {
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