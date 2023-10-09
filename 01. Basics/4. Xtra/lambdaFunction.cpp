// Lambda Function in C++

#include<iostream>
using namespace std;

int main() {

    // adding 2 in a number 'x'
    // cout << [](int x){return x+2;}(2) << endl;
    auto add2 = [](int x){return x+2;};
    cout << add2(2) << endl;


    // adding 2 numbers
    // cout << [](int x, int y){return x+y;}(2,3) << endl;
    auto sum = [](int x, int y){return x+y;};
    cout << sum(2,3) << endl;
    
    return 0;
}