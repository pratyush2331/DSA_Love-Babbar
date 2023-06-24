// 

#include<iostream>
using namespace std;

int main() {
	string s = "abcabc";

	s[0] = "p";
	for(int i = 0; i < s.length(); i++) {
		cout << s[i] << " ";
	}
	cout << endl;
	
	return 0;
}