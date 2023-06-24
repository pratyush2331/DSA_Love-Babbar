// Intro to 2-D arrays
// taking i/p & printing o/p

#include<iostream>
using namespace std;

int main() {
    int a[100][100];
    int m, n; // m -> rows, n -> cols
    cout << "Enter rows & cols : ";
    cin >> m >> n;

    cout << "Enter elements in a matrix : " << endl;

    // Taking i/p --> row wise
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // Taking i/p --> col wise
    /*
    for(int j = 0; j < n; j++) {
            for(int i = 0; i < m; i++) {
                cin >> a[i][j];
            }
    }
    */

    // Printing array --> row wise
    cout << "Row wise : " << endl;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout<<endl;
    }

    // Printing array --> column wise
    cout << "Column wise : " << endl;
    for(int j = 0; j < n; j++) {
        for(int i = 0; i < m; i++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}