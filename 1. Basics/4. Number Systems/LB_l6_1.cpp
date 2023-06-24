// Decimal to Binary

#include<iostream>
#include<math.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 0, i=0;
    bool bit;
    while(n) {
        bit = n&1;
        ans = (bit * pow(10, i)) + ans;
        n = n >> 1;
        i++;
    }
    cout << "Answer = " << ans << endl;
    return 0;
}