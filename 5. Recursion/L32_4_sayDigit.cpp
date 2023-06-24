// print digit in words

#include<iostream>
using namespace std;

void sayDigit(int n, string str[]) {
    
    if(n == 0)
        return ;

    sayDigit(n/10, str);

    cout << str[n%10] << " ";
}

int main() {
    string str[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int n;
    cin >> n;
    cout << endl;

    sayDigit(n, str);
    
    return 0;
}