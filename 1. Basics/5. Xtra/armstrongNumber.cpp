// Coding Ninjas - 3 : Check Armstrong
// Armstrong Numbers: 1, 2, 3, 4, 5, 6, 7, 8, 9, 153, 370, 371, 407, 1634, 8208, 9474, 54748.......
/*
sample i/p-1:
371

sample o/p-1:
true
---------------------------------------------
sample i/p-2:
1260

sample o/p=2:
false
*/

#include<iostream>
#include<cmath>
using namespace std;

int main() {
    int num;
    cin >> num;

    // Checking for non-positive integers
    if(num <= 0) {
        cout << "false" << endl;
        return 0;
    }

    int temp = num;

    // For claculating length
    int count = 0;
    while(temp) {
        count++;
        temp /= 10;
    }

    // For calculating ans
    temp = num;
    int ans = 0;
    while(temp) {
        int digit = temp%10;

        ans += pow(digit, count);

        temp /= 10;
    }

    // cout << ans << endl;

    if(ans == num) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }

    return 0;
}