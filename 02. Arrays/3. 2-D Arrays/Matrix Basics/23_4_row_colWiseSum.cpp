// Coding Ninjas : Row Wise & Col Wise Sum

#include<iostream>
using namespace std;

// Row wise Sum
void rowWiseSum(int arr[][3], int n, int m) {
    cout << "Row wise Sum : " << endl;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < m; j++) {
            sum += arr[i][j];
        }
        cout << "Row-"<<i<<" sum : " << sum << endl;
    }
}

// Column wise Sum
void colWiseSum(int arr[][3], int n, int m) {
    cout << "Column wise Sum : " << endl;
    for(int j = 0; j < m; j++) {
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i][j];
        }
        cout << "Col-"<< j <<" sum : " << sum << endl;
    }
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

    rowWiseSum(arr, n, m);

    colWiseSum(arr, n, m);

    return 0;
}