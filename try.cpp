#include <iostream>
#include <vector>
#include <map>
using namespace std;

int beautifulNodes(int N, int A[]) {
    for (int i = 1; i <= N; i++) {
        mp[A[i]]++;
    }

    int beautiful_nodes_count = 0;
    for (int i = 2; i <= N; i++) {
        
    }
    
    return beautiful_nodes_count;
}

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        // Input for each test case
        int N;
        cin >> N;
        vector<int> A(N+1);
        for (int i = 2; i <= N; i++) {
            cin >> A[i];
        }

        // Calculate and print the count of beautiful nodes for each test case
        int result = beautifulNodes(N, A);
        cout << result << endl;
    }

    return 0;
}