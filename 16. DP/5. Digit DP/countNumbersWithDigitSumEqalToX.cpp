// Q. Find the count of the numbers b/w L and R which have sum of digits = X
// 1 <= L <= R <= 10^18
// 1 <= X <= 180

#include<iostream>
using namespace std;

// Brute Force
bool check(int num, int X) {
    int sum_digit = 0;
    while(num) {
        sum_digit += num%10;
        num /= 10;
    }
    return sum_digit == X;
}

int bruteForce(int L, int R, int X) {
    int cnt = 0;
    for(int num = L; num <= R; num++) {
        if(check(num, X)) cnt++;
    }
    return cnt;
}

int main() {
    int L = 1, R = 15, X = 5;

    cout << bruteForce(L, R, X) << endl;
    
    return 0;
}