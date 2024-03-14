// Count Inversions
// Coding Ninjas : https://www.codingninjas.com/studio/problems/count-inversions_615

/*
TC : O(n.logn) --> merge sort TC
SC : O(n) --> merge sort space
*/

#include<bits/stdc++.h>

using namespace std;


// method-1 : w/o using local variable
int merge(long long* arr, int s, int e) {
	int cnt = 0;

	int mid = s + (e-s)/2;

	int len1 = mid-s+1;
	int len2 = e-mid;

	long long* arr1 = new long long[len1];
	long long* arr2 = new long long[len2];

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
		if(arr1[i] <= arr2[j]) {
			arr[mainArrayIndex++] = arr1[i++];
		}
		else {
			arr[mainArrayIndex++] = arr2[j++];
            cnt += (mid - s - i + 1);
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

	return cnt;
}

int mergeSort(long long* arr, int s, int e) {
	int cnt = 0;
    // base case
    if(s >= e) return 0;

    int mid = s + (e-s)/2;

    // left part sort krna h
    cnt += mergeSort(arr, s, mid);

    // right part sort krna h
    cnt += mergeSort(arr, mid+1, e);

    // merge krna h
    cnt += merge(arr,s, e);

	return cnt;
}

long long getInversions(long long *arr, int n){
    return mergeSort(arr, 0, n-1);
}



// method-0 : with using local variable (not recommended)
/*
int cnt = 0;

void merge(long long* arr, int s, int e) {
	int mid = s + (e-s)/2;

	int len1 = mid-s+1;
	int len2 = e-mid;

	long long* arr1 = new long long[len1];
	long long* arr2 = new long long[len2];

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
		if(arr1[i] <= arr2[j]) {
			arr[mainArrayIndex++] = arr1[i++];
		}
		else {
			arr[mainArrayIndex++] = arr2[j++];
            cnt += (mid - s - i + 1);
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

void mergeSort(long long* arr, int s, int e) {
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

long long getInversions(long long *arr, int n){
    mergeSort(arr, 0, n-1);

    return cnt;
}
*/


int main() {
    

    return 0;
}