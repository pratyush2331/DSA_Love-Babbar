// GFG : Count Inversions
/*
Example 1:
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).

Example 2:
Input: N = 5
arr[] = {2, 3, 4, 5, 6}
Output: 0
Explanation: As the sequence is already 
sorted so there is no inversion count.

Example 3:
Input: N = 3, arr[] = {10, 10, 10}
Output: 0
Explanation: As all the elements of array 
are same, so there is no inversion count.
*/
/*
Expected Time Complexity: O(NLogN).
Expected Auxiliary Space: O(N).

Constraints:
1 ≤ N ≤ 5*105
1 ≤ arr[i] ≤ 1018
*/

#include<iostream>
using namespace std;

void merge(long long arr[], long long int &count, long long int start, long long int mid, long long int end){
    long long temp[end-start+1];
    long long int i=start;
    long long int j=mid+1;
    long long int k=0;
    while(i<=mid && j<=end){
        if(arr[i]>arr[j]){
            temp[k++]=arr[j++];
            count+= mid-i+1;
        }
        else{
            temp[k++]=arr[i++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=end){
        temp[k++]=arr[j++];
    }
    
    for(long long int i=start; i<=end; i++){
        arr[i]=temp[i-start];
    }
}

void mergeSort(long long arr[], long long int &count, long long int start, long long int end){
    if(start<end){
        long long int mid=start+(end-start)/2;
        mergeSort(arr,count,start,mid);
        mergeSort(arr,count,mid+1,end);
        merge(arr,count,start,mid,end);
    }
}

long long int inversionCount(long long arr[], long long N)
{
    long long int count=0;
    mergeSort(arr,count,0,N-1);
    return count;
}

int main() {
    long long t;
    cin >> t;

    while(t--) {
        long long n;
        cin >> n;

        long long* arr = new long long[n];

        for(long long i = 0; i < n; i++) {
            cin >> arr[i];
        }

        cout << "Inversion Count = " << inversionCount(arr, n);

        delete[] arr;
    }
    
    return 0;
}