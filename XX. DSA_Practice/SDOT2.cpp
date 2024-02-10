// 

#include<iostream>
using namespace std;

int main() {
    
    return 0;
}









// Toggle the switch
/*
#include<iostream>
#include<vector>
using namespace std;

void getToggle(int n) {
    vector<bool> arr(n, false);
    
    int count = 1;
    while(count <= n) {
        for(int i = count; i <= n; i += count) {
            arr[i-1] = !arr[i-1];
        }
        count++;
    }

    
    for(int i = 0; i < n; i++) {
        if(arr[i] == true)
            cout << i+1 << " ";
    }
}

int main() {
    int n;
    cin >> n;

    getToggle(n);
    
    return 0;
}
*/







// Strobogrammatic Number
/*
#include<iostream>
using namespace std;

// strobogrammatic number from 0 to 9 (single digit)
// strobogrammatic_number = {0, 1, 8}
// 0 -> 0
// 1 -> 1
// 6 -> 9
// 8 -> 8

bool isStrobogrammatic(string str) {
    string temp = str;

    int s = 0, e = str.length()-1;
    while(s < e) {
        if((str[s] == '0' && str[e] == '0') || (str[s] == '1' && str[e] == '1') || (str[s] == '8' && str[e] == '8') || (str[s] == '6' && str[e] == '9') || str[s] == '9' && str[e] == '6') {
            s++; e--;
            continue;
        }
        else
            return 0;
    }
    
    return 1;
}

int main() {
    string str;
    cin >> str;

    if(isStrobogrammatic(str))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    return 0;
}
*/




// SDOT - 2

// Chinese Remainder's Theorem
/*
#include<iostream>
#include<vector>
using namespace std;

int getMinX(vector<int>& m, vector<int>& a, int n) {
    int P = 1;
    for(auto ele : m)
        P *= ele;
    
    vector<int> M;
    for(auto ele : m) {
        M.push_back(P/ele);
    }

    // finding yi
    vector<int> yi;
    for(int i = 0; i < n; i++) {
        for(int yPossible = 0; yPossible < 1e5; yPossible++) {
            if((M[i]*yPossible) % m[i] == 1) {
                yi.push_back(yPossible);
                break;
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += (a[i] * M[i] * yi[i]);
    }

    return sum % P;
}

int main() {
    int n;
    cin >> n;

    vector<int> m, a;
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        m.push_back(data);
    }
    for(int i = 0; i < n; i++) {
        int data;
        cin >> data;
        a.push_back(data);
    }

    cout << getMinX(m, a, n) << endl;
    
    return 0;
}
*/



// code-2 : combination
/*
#include<iostream>
#include<vector>
using namespace std;

void solve(vector<int>& arr, int r, int i, vector<int>& temp, vector<vector<int>>& ans) {
    if(i >= arr.size()) {
        return;
    }

    if(r == 0) {
        ans.push_back(temp);
        return;
    }

    // take
    temp.push_back(arr[i]);
    solve(arr, r-1, i+1, temp, ans);

    // not take
    temp.pop_back();
    solve(arr, r, i+1, temp, ans);

}

vector<vector<int>> getCombination(vector<int>& arr, int r) {
    vector<vector<int>> ans;
    vector<int> temp;

    solve(arr, r, 0, temp, ans);

    return ans;
}

int main() {
    int n, r;
    cin >> n >> r;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<vector<int>> ans = getCombination(arr, r);

    cout << "possible combination = " << endl;
    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
*/



// code-1
/*
#include<iostream>
using namespace std;

string rearrange(string str) {
    int n = str.size();
    int j = n-1;
    for(int i = n-1; i >= 0; i--) {
        if(str[i] != '_') {
            swap(str[i], str[j]);
            j--;
        }
    }
    return str;
}

int main() {
    string str;
    cin >> str;

    cout << rearrange(str) << endl;
    
    return 0;
}
*/