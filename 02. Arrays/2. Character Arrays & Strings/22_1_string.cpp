// length of string, reverse a string, check palindrome, to LowerCase

#include<iostream>

using namespace std;

void reverse(char name[], int n);
bool checkPalindrome(char name[], int n);
char toLowerCase(char ch);

int getLength(char name[]) {
    int i = 0;
    while(name[i] != '\0') {
        i++;
    }

    return i;
}

void reverse(char name[], int n) {
    int s = 0, e = n-1;
    while(s < e) {
        swap(name[s++], name[e--]);
    }
}

bool checkPalindrome(char name[], int n) {
    int s = 0, e = n-1;
    while(s < e) {
        if(toLowerCase(name[s]) != toLowerCase(name[e])) 
            return 0;

        s++;
        e--;
    }
    return 1;
}


// we can also use: toupper(), tolower(), isupper(), islower(), isalpha(), isalnum()..........
char toLowerCase(char ch) {
    if(ch >= 'A' && ch <= 'Z') {
        return ch - 'A' + 'a';
    }
    else {
        return ch;
    }
}

int main() {
    char name[20];

    cout<<"Enter your name: "<<endl;
    cin>>name;

    cout<<"Your name is "<<name<<endl;

    int len = getLength(name);
    cout<<"Length of name = "<<len<<endl;

    reverse(name, len);
    cout<<"Reverse of name is "<<name<<endl;

    cout<<"Palindrome or not ? "<<checkPalindrome(name, len)<<endl;

    cout << toLowerCase('b') << endl;
    cout << toLowerCase('B') << endl;
    cout << toLowerCase('2') << endl;

    return 0;
}