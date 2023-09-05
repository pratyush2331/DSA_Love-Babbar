// 

#include<iostream>
using namespace std;


// Get i-th Bit
bool getBit(int num, int i) {
	return num & (1 << i);
}

// Set i-th Bit
bool setBit(int& num, int i) {
	return num = num | (1 << i);
}

// Clear i-th Bit
bool clearBit(int& num, int i) {
	return num = num & ~(1 << i);
}


int main() {
	int num, i;
	cin >> num >> i;

	cout << " i-th bit = " << getBit(num, i) << endl;

	cout << setBit(num, i) << endl;
	cout << " num = " << num << endl;

	cout << clearBit(num, i) << endl;
	cout << " num = " << num << endl;
    
    return 0;
}