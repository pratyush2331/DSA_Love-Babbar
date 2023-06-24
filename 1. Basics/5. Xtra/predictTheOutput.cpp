// How many times "Hi" will be printed in the screen

#include<iostream>
using namespace std;

bool print() {
	cout << "Hi" << endl;
	return 1;
	// return 0;
}

int main() {
	if(print() && print()) {
		print();
	}
	return 0;
}