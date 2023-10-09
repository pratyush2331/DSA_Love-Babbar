// Print sum of largest row and its inndex

#include<iostream>
using namespace std;

void largestRowSum(int arr[][3], int n, int m) {
    int rowIndex = -1;
    int rowSum = INT_MIN;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum += arr[i][j];
        }
        if(sum > rowSum) {
            rowIndex = i;
            rowSum = sum;
        }
    }

    cout << "index of largest row : " << rowIndex << endl;

    cout << "sum of largest row : " << rowSum << endl;
}

int main() {

    int arr[3][3];

    int n = 3, m = 3;

    cout << "Enter elements : " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "Printing Elements : " << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    largestRowSum(arr, n, m);

    return 0;
}