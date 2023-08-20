// Kaprekar Number
// GFG : https://practice.geeksforgeeks.org/problems/kaprekar-number1051/1

/*
Example 1:

Input:
N=45
Output:
1
Explanation:
45*45=2025. Now, 20+25=45.
Thus, 45 is a kaprekar number.
--------------------------------------------------------------------------

Example 2:

Input:
N=20
Output:
0
Explanation:
20*20=400.There is no way to divide
400 into two parts such that their sum is equal
to 20.So, 20 is not a kaprekar number.
*/

#include<iostream>
#include<cmath>
using namespace std;

class Solution {
    public:
	bool isKaprekar(int N) {
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
};

int main() {
	// int t;
    // cin >> t;
    // while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isKaprekar(N) << endl;
	// }
}