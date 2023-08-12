// 

#include<iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter x : ";
    cin >> x;

    int ans;
    // 1's complement
    ans = ~x;
    cout << "1's complement : " << ans << endl;

    // 2's complement
    ans = ~x + 1;
    cout << "2's complement : " << ans << endl;
    // [OR]
    ans = -x;
    cout << "2's complement : " << ans << endl;

    // right most set bit mask (rsbm)
    ans = x & (-x);
    cout << "right most set bit mask : " << ans << endl;

    // Kernighan's Algorithm : Count set bits
    // uses/applications : Fenwick Tree [OR] Binary Indexed Tree (BIT)
    int count = 0;
    while(x) {
        int rsbm = x & (-x);
        x -= rsbm;
        count++;
    }
    cout << "total number of set bits : " << count << endl;
    
    return 0;
}