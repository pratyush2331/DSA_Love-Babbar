// Prateek and his Friends
// HackerEarth : https://www.hackerearth.com/practice/basic-programming/implementation/basics-of-implementation/practice-problems/algorithm/prateek-and-his-friends/

/*
Problem
Prateek wants to give a party to his N friends on his birthday, where each friend is numbered from 1 to N. His friends are asking for a gift to come to the party, instead of giving him one. The cost of the gifts are given in the array Value where ith friend asks for a gift which has a cost Cost[i].

But, Prateek has only X amount of money to spend on gifts and he wants to invite his friends which are in continuous range such that sum of the cost of the gifts of those friends will be exactly equal to X.

If he can invite his friends, who can satisfy the above condition then, print YES otherwise print NO.

Input:
The first line contains a single integer T, denoting the number of test cases. In each test case, the following input will be present: - The next line contains two space-separated integers N and X, where N represents the number of friends and X represents amount of money which Prateek can spend on gifts.
- Next N line contains N integers, where ith line contains ith integer, which represents the Costi .

Ouput
Output exactly T lines, each containing the answer to the corresponding test case .

Constraints:
1 <= T <= 10
1 <= N , Cost[i] <= 10^6
1 <= X <= 10^12
*/

/*
Sample Input
1
5 12
1 3 4 5 2

Sample Output
YES

Explanation
In the sample input, T is equal to 1. So, accordingly, in next line, values of N and X are given which are 5 and 12 respectively. In the next 5 lines, you have costi asked by ith friend. As friends numbered from 2 to 4 (inclusively) have gifts value which are {3, 4, 5}, and their sum equals to 12 - that is, the given value of X. So, the answer is YES.
*/

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;

	while(t--) {
		long int N, X;
		cin >> N >> X;

		// input array leliye
		long int arr[1000000];
		for(int i = 0; i < N; i++) {
			cin >> arr[i];
		}

		long int sum = 0;
		bool flag = 0;
		int start = 0;
		for(int i = 0; i < N; i++) {
			sum += arr[i];

			while(sum > X) {
				sum -= arr[start];
				cout << start<< " ";
				start++;
			}

			if(sum == X) {
				flag = 1;
				break;
			}
		}

		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}
