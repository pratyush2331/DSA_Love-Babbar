// Kaprekar Number
// GFG : https://practice.geeksforgeeks.org/problems/kaprekar-number1051/1

#include<iostream>
#include<cmath>
using namespace std;

int isKaprekar(int N) {
	int temp = N*N;
	int leftPart = 0, rightPart = 0;
	int i = 0;
	while(temp) {
		int digit = temp%10;
		rightPart += digit * pow(10, i);
		leftPart = temp / 10;
		
		// cout << leftPart << " " << rightPart << endl;
		
		if(leftPart+rightPart == N && leftPart && rightPart) {
			return 1;
		}
		
		i++;
		temp /= 10;
	}
	return 0;
}

int main() {
	int n;
	cin >> n;

	cout << isKaprekar(n) << endl;

	return 0;
}