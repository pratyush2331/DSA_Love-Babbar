// Upper Case, Lower Case, Number OR Special Case

#include<iostream>
using namespace std;

int main(){
    char ch;
    ch = cin.get();
    if(ch>='A' && ch<='Z')
        cout<<"Upper Alphabet\n";
    else if(ch>='a' && ch<='z')
        cout<<"Lower Alphabet\n";
    else if(ch>='0' && ch<='9')
        cout<<"Number\n";
    else    cout<<"Special Character\n";
    return 0;
}