// CodeStudio : (DSA - paid video)
/*
sample i/p:
abcd

sample o/p:
a
ab
abc
abcd
*/

#include<iostream>
#include<cstring>
using namespace std;

void printAllPrefixes(char input[]) {
    // i represents end index of my prefix
    for(int i = 0; input[i] != '\0'; i++) {
        // j represents starting index of my prefix
        for(int j = 0; j <= i; j++) {
            cout << input[j];
        }
        cout << endl;
    }
}

int main() {
    char input[100] = "abcd";
    printAllPrefixes(input);
    return 0;
}