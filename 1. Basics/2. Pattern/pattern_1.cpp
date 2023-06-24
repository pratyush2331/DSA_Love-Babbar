// left hand triangle in O(n)

#include<iostream>
using namespace std;

int main() {
	
	int n;
	cin >> n;

	string str = "";
	string s = "* ";
	for(int i = 0; i < n; i++) {
		str = str + s;
		cout << str;
		cout << endl;
	}

	return 0;
}