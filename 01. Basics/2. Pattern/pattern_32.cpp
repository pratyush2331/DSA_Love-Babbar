// 
/*
for n = 4
1=1
1+2=3
1+2+3=6
1+2+3+4=10
----------------------------------------------
for n = 5
1=1
1+2=3
1+2+3=6
1+2+3+4=10
1+2+3+4+5=15
*/

#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int sum = 0;
        for(int j = 1; j <= i; j++) {
            sum += j;
            cout << j;
            if(j != i) cout << "+";
        }
            cout << "=" << sum << endl;
    }
    return 0;
}