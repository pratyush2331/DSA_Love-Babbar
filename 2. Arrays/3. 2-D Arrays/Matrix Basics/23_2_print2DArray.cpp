// print 2-D array using function

#include<iostream>
using namespace std;

void printMatrix(int b[][5], int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // int b[3][2] = { 1, 2, 3, 4, 5, 6 };
    // int b[3][2] = { {1, 2}, {3, 4}, {5, 6} };

    int b[5][5] = { {1, 2}, {3, 4} };
    printMatrix(b, 5, 5);
    
    /*
    int b[][5] = { {1, 2}, {3, 4} };
    printMatrix(b, 2, 5);
    */

    /*
    int b[][2] = { {1, 2}, {3, 4} };
    printMatrix(b, 2, 2);
    */

    /*
    int b[100][5];
    int m, n;
    cout << "Enter rows & cols : ";
    cin >> m >> n;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }
    printMatrix(b, m, n);
    */

    return 0;
}