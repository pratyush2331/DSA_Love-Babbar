// memset()

#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int n;
	cin >> n;

	int arr[n];
	memset(arr, -11, sizeof(arr));

	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;

	return 0;
}