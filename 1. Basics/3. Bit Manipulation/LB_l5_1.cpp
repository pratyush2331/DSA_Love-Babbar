// Bitwise Operators

#include<iostream>
using namespace std;

int main(){

                // Bitwise Operators
    // int a=4, b=6;
    // cout<<"a&b= "<<(a&b)<<endl;       // 4
    // cout<<"a|b= "<<(a|b)<<endl;       // 6
    // cout<<"~a= "<<~a<<endl;           // -5
    // cout<<"~b= "<<~b<<endl;           // -7
    // cout<<"a^b= "<<(a^b)<<endl;       // 2

                // Left Shift & Right Sift Operator
                //  Trick:-
                //     a<<b  --->  a*b
                //     a>>b  --->  a/b
    // cout<<"(5<<1) = "<<(5<<1)<<endl;     // 10
    // cout<<"(17>>1) = "<<(17>>1)<<endl;   // 8
    // cout<<"(17>>2) = "<<(17>>2)<<endl;   // 4
    // cout<<"(19<<1) = "<<(19<<1)<<endl;   // 38
    // cout<<"(21<<2) = "<<(21<<2)<<endl;   // 84

                // Increment & Decrement Operators
                //     i++, ++i, i--, --i
    // int i=7;
    // cout<<"\ni = "<<i<<endl;           // 7
    // cout<<"(++i) = "<<(++i)<<endl;     // 8
    // // 8, i=8
    // cout<<"(i++) = "<<(i++)<<endl;     // 8
    // // 8, i=9
    // cout<<"(i--) = "<<(i--)<<endl;     // 9
    // // 9, i=8
    // cout<<"(--i) = "<<(--i)<<endl;     // 7
    // // 7, i=7

                // Special Case (cascade) :    Left ---> Right
    // int i=7;
    // cout<<"\ni = "<<i<<endl;           // 7
    // cout << "i << ++i << i++ << --i << i-- << ++i << i:\t" << i << " " << ++i << " " << i++ << " " << --i << " " << i-- << " " << ++i << " " << i << endl;  // 7 8 8 8 8 8 8

    return 0;
}