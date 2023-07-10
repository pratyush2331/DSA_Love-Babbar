// Print All Substrings

// same question : "LoveBabbar_DSA\5. Recursion\L37_2_subSequences.cpp"

/*
Sample Input 1:
abc

Sample Output 1:
a 
ab 
abc 
b 
bc 
c 

Sample Input 2:
co

Sample Output 2:
c 
co 
o
*/

#include<iostream>
using namespace std;

void printSubstrings(char input[]) {
    for(int i = 0; input[i] != '\0'; i++) {
        for(int j = i; input[j] != '\0' ; j++) {
            for(int k = i; k <= j; k++) {
                cout<<input[k];
            }
            cout<<endl;
        }
    }
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    printSubstrings(str);
    return 0;
}