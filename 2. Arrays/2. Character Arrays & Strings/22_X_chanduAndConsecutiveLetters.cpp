// HackerEarth : Chandu and Consecutive Letters
/*
Problem:
Chandu is very fond of strings. (Or so he thinks!) But, he does not like strings which have same consecutive letters. No one has any idea why it is so. He calls these strings as Bad strings. So, Good strings are the strings which do not have same consecutive letters. Now, the problem is quite simple. Given a string S, you need to convert it into a Good String.

Sample i/p:
3
abb
aaab
ababa

Sample o/p:
ab
ab
ababa
*/

#include <iostream>
#include<cstring>
using namespace std;

int main() {
	int num;
	cin >> num;    //Reading input from STDIN

	while(num--) {
		char str[1000];
		cin >> str;

		char ch[1000];
		int count = 0;
		for(int i = 0; i < strlen(str); i++) {
			if(str[i] != str[i+1]) {
				cout << str[i];
			}
		}
		cout << endl;
	}

	// cout << "Input number is " << num << endl;	// Writing output to STDOUT
}