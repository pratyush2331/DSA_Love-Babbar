// Insertion Sort
/*
Time Complexity-
    Best Case : O(n)
    Worst Case: O(n^2)
*/
/*
sample i/p-1:
1
7
10 4 -1 0 0 5 121
sample o/p-1: 
-1 0 0 4 5 10 121 

sample i/p-2:
1
5
5 4 3 2 1
sample o/p-2:
1 2 3 4 5
*/

#include<iostream>
using namespace std;

void display(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

// Modified Insertion Sort
void insertionSort(int arr[], int n) {
    for(int i = 2; i < n; i++) {                // For Number of Pass = n-1

		arr[0] = arr[i];
		// cout << arr[0] << endl;
		int j = 1;

		while(j < i && arr[j] <= arr[0]) {        // Checking for need of Shifting
			j++;
		}
		int temp = arr[j];
		arr[j] = arr[0];
		// cout << "arr[j+1] = " << arr[j+1];
		int temp2;
		while(j < i) {
			temp2 = arr[j+1];
			arr[j+1] = temp;
			temp = temp2;
			// temp = arr[j+1];
			display(arr, n);
			j++;
		}

		// display(arr, n);
		cout << endl;

    }
}

int main() {
    int t;
    cin>>t;

    while(t--) {
        int n;
        cin>>n;
		n++;

		int* arr = new int[n];

        for(int i = 1; i < n; i++) {
            cin>>arr[i];
        }

		// 0th Index will be used for storing...
		arr[0] = 0;
		
		cout << endl;
        display(arr, n);
		cout << endl;
        insertionSort(arr, n);
		cout << endl;
        display(arr, n);

		delete[] arr;
    }
    return 0;
}
