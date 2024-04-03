// Program to check given year is a Leap Year or not

#include<bits/stdc++.h>

using namespace std;

void checkLeapYear(int year) {
    if(year % 4 == 0) {
        if(year % 100 == 0) {
            if(year % 400 == 0) {
                cout << "Leap Year\n";
            }
            else {
                cout << "Not a Leap Year\n";
            }
        }
        else {
            cout << "Leap Year\n";
        }
    }
    else {
        cout << "Not a Leap Year\n";
    }
}

int main() {
    int year;
    cout << "Enter Year : ";
    cin >> year;

    checkLeapYear(year);

    return 0;
}