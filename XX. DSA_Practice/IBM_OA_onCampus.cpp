// IBM Online Assessment Question


// Problem-1

/*
#include<bits/stdc++.h>
using namespace std;

// Touching
// Concentric
// Intersecting
// Disjoint-Outside
// Disjoint-Inside

string solve(int a, int r1, int b, int r2) {
    int al = a - r1;
    int ar = a + r1;
    int bl = b - r2;
    int br = b + r2;

    // Concentric - center same
    if (a == b) {
        return "Concentric";
    }

    // Touching - same boundary
    else if (al == br || ar == bl || ar == br || al == bl) {
        return "Touching";
    }

    // Disjoint-Inside
    else if((bl < al && al < br && bl < ar && ar < br) || (al < bl && bl < ar && al < br && br < ar)) {
        return "Disjoint-Inside";
    }

    // Intersecting - a -> b || b -> a
    else if ((bl < ar && ar < br) || (bl < al && al < br) || (al < bl && bl < ar) || (al < br && br < ar)) {
        return "Intersecting";
    }


    // Disjoint-Outside
    else if (ar < bl || br < al) {
        return "Disjoint-Outside";
    }
    else {
        return "error"; // not handled perfectly
    }
}

vector<string> circles(const vector<string>& circlePairs) {
    vector<string> ans;

    for (int i = 0; i < circlePairs.size(); i++) {
        pair<int, int> a;
        int r1;
        pair<int, int> b;
        int r2;

        int k = 0;
        string str;

        istringstream ss(circlePairs[i]);
        ss >> a.first >> a.second >> r1 >> b.first >> b.second >> r2;

        cout << a.first << " " << a.second << " " << r1 << endl;
        cout << b.first << " " << b.second << " " << r2 << endl;

        int distanceA = a.first != 0 ? a.first : a.second;
        int distanceB = b.first != 0 ? b.first : b.second;

        ans.push_back(solve(distanceA, r1, distanceB, r2));
    }

    return ans;
}

int main() {

    // random test-case
    // vector<string> circlePairs = {
    //     "3 0 10 5 0 3", // Disjoint-Inside
    //     "0 1 4 0 1 5", // Concentric
    //     "12 0 21 14 0 23", // Touching
    //     "37 0 5 30 0 11", // Intersecting
    // };

    // test-case : 0
    // vector<string> circlePairs = {
    //     "12 0 21 14 0 23",
    //     "0 45 8 0 94 9",
    //     "35 0 13 10 0 38",
    //     "0 26 8 0 9 25"
    // };

    // test-case : 1
    vector<string> circlePairs = {
        "0 5 9 0 9 7",
        "0 15 11 0 20 16",
        "26 0 10 39 0 23",
        "37 0 5 30 0 11",
        "41 0 0 28 0 13",
    };


    int n = circlePairs.size();
    vector<string> ans = circles(circlePairs);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
*/


// Problem-1

/*
int countFaults(int n, vector<string> logs) {
    unordered_map<int, int> mp(n, 0);
    
    unordered_map<string , vector<string>> faultyServers; // A dictionary to keep track of faulty servers
    int replacements = 0; // Initialize the count of replacements to 0

    for (const string& log : logs) {
        size_t spacePos = log.find(' ');
        string server_id = log.substr(0, spacePos);
        string status = log.substr(spacePos + 1);

        if (faultyServers.find(server_id) != faultyServers.end()) {
            faultyServers[server_id].push_back(status); // Add the status to the server's history
        } else {
            faultyServers[server_id] = { status }; // Initialize the server's history with the current status
        }

        // Check if the server is faulty
        if (faultyServers[server_id].size() >= 3) {
            bool allErrors = true;
            for (int i = faultyServers[server_id].size() - 3; i < faultyServers[server_id].size(); ++i) {
                if (faultyServers[server_id][i] != "error") {
                    allErrors = false;
                    break;
                }
            }

            if (allErrors) {
                replacements++;
                faultyServers[server_id].clear(); // Replace the server and reset its history
            }
        }
    }

    return replacements;
}
*/