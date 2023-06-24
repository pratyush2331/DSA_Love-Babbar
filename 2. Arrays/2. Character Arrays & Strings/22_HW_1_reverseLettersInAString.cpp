// Reverse letters in a string
/*
sample i/p:
My name is Ram

sample o/p:
yM eman si maR
*/

#include<iostream>
#include<cstring>
using namespace std;

void reverseStringLetterWise(char input[]) {
    // 2- pointer approach
    int len = strlen(input);
    int s, e;
    int i = 0;
    while(input[i] != '\0') {
        s = i;
        while(input[i] != ' ' && input[i] != '\0') {
            i++;
        }
        e = i - 1;
        while(s < e) {
            swap(input[s++], input[e--]);
        }
        i++;
    }
}

int main() {
    char input[1000];
    cin.getline(input, 1000);
    reverseStringLetterWise(input);
    cout<<input<<endl;
    return 0;
}