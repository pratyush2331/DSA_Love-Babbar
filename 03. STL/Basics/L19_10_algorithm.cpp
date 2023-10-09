// C++ algorithm in STL

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    vector<int> v;

    v.push_back(1);
    v.push_back(3);
    v.push_back(6);
    v.push_back(6);
    v.push_back(6);
    v.push_back(7);
    v.push_back(9);
    v.push_back(10);

    for(auto i : v) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    cout<<"5 is present or not ? -> "<<binary_search(v.begin(), v.end(), 5)<<endl;
    cout<<"6 is present or not ? -> "<<binary_search(v.begin(), v.end(), 6)<<endl;
    cout<<endl;

    cout<<"lower bound of 6 -> "<<lower_bound(v.begin(), v.end(), 6) - v.begin()<<endl;
    cout<<"upper bound of 6 -> "<<upper_bound(v.begin(), v.end(), 6) - v.begin()<<endl;
    cout<<endl;

    int a = 3;
    int b = 5;

    cout<<"max(a, b) -> "<<max(a, b)<<endl;
    cout<<"min(a, b) -> "<<min(a, b)<<endl;
    cout<<endl;
    
    cout<<"Before Swap"<<endl;
    cout<<"a -> "<<a<<endl;
    cout<<"b -> "<<b<<endl;
    cout<<endl;
    
    swap(a, b);

    cout<<"After Swap"<<endl;
    cout<<"a -> "<<a<<endl;
    cout<<"b -> "<<b<<endl;
    cout<<endl;

    string abcd = "abcdfbnm";
    reverse(abcd.begin(), abcd.end());
    cout<<"string -> "<<abcd<<endl;
    cout<<endl;


    cout<<"Before rotating vector by 1"<<endl;
    for(auto i : v) {
        cout<<i<<" ";
    }
    cout << endl;
    cout<<"After left rotating vector by 1"<<endl;
    rotate(v.begin(), v.end()-1, v.end());
    for(auto i : v) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"After right rotating vector by 1"<<endl;
    rotate(v.begin(), v.begin()+1, v.end());
    for(auto i : v) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    // sort() ---> implemented using Introsort ---> hybrid of Quick Sort, Heap Sort & Insertion Sort.
    sort(v.begin(), v.end());
    cout<<"After Sorting"<<endl;
    for(auto i : v) {
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<endl;

    return 0;
}