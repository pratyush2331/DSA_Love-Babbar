// Merge Sort

/*
TC:-
Best Case : O(n log n)
Worst Case : O(n log n)

SC : O(n)
*/

// HW : do in O(1) SC (HINT : using index)

#include<iostream>
using namespace std;

void merge(int* arr, int s, int e) {
	int mid = s + (e-s)/2;

	int len1 = mid-s+1;
	int len2 = e-mid;

	int* arr1 = new int[len1];
	int* arr2 = new int[len2];

	int mainArrayIndex = s;
	for(int i = 0; i < len1; i++) {
		arr1[i] = arr[mainArrayIndex++];
	}
	for(int i = 0; i < len2; i++) {
		arr2[i] = arr[mainArrayIndex++];
	}

    // merge 2 sorted arrays
	int i = 0, j = 0;
	mainArrayIndex = s;
	while(i < len1 && j < len2) {
		if(arr1[i] < arr2[j]) {
			arr[mainArrayIndex++] = arr1[i++];
		}
		else {
			arr[mainArrayIndex++] = arr2[j++];
		}
	}
	while(i < len1) {
		arr[mainArrayIndex++] = arr1[i++];
	}
	while(j < len2) {
		arr[mainArrayIndex++] = arr2[j++];
	}

	delete[] arr1;
	delete[] arr2;
}

void mergeSort(int* arr, int s, int e) {
    // base case
    if(s >= e) return ;

    int mid = s + (e-s)/2;

    // left part sort krna h
    mergeSort(arr, s, mid);

    // right part sort krna h
    mergeSort(arr, mid+1, e);

    // merge krna h
    merge(arr,s, e);
}

void display(int* arr, int n) {
    for(int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int n;
    cin >> n;

    // creating array Dynamically
    int*arr = new int[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n-1);

    display(arr, n);

    // memory deletion
    delete[] arr;

    return 0;
}