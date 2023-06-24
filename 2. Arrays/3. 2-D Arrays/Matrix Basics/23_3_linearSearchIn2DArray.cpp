// Linear Search in 2D Array

#include<iostream>
using namespace std;

// TC : O(n*m),    n --> rows, m --> cols
bool isPresent(int arr[][4], int rows, int cols, int target) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            if(arr[i][j] == target) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {

    int arr[3][4];

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    int target = 4;

    cout << "Element present ? " << isPresent(arr, 3, 4, target) << endl;
    
    return 0;
}