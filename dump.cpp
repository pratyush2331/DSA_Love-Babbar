// #include<bits/stdc++.h>

// using namespace std;

// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);


//     vector<int> A = {1,1,1,2,2,2};
//     // vector<int> A = {5, 3, 3, 2, 5, 2, 3, 2};
//     // vector<int> A = {127,15,3,8,10};
//     // vector<int> A = {1,1,2,2,3,3};

//     unordered_map<int,int> mp;
//     for(auto ele : A) {
//         mp[ele]++;
//     }

//     // Store frequencies in a multiset (automatically sorted)
//     multiset<int> frequencies;
//     for(auto ele : mp) {
//         frequencies.insert(ele.second);
//     }

//     int cnt = 0;
//     while (!frequencies.empty()) {
//         int freq = *frequencies.rbegin(); // largest frequency
//         frequencies.erase(prev(frequencies.end()));

//         // Check if this frequency already exists
//         if (!frequencies.empty() && frequencies.count(freq) > 0) {
//             // If so, decrement the frequency and increment the counter
//             if (freq > 1) {
//                 frequencies.insert(freq - 1);
//             }
//             cnt++;
//         }
//     }

//     cout << cnt << "\n";
    
//     return 0;
// }

// --------------------------------------------------------------------------------------------------------------

// #include <bits/stdc++.h>

// using namespace std;

// // Function to calculate the maximum cultivable area with at most two rectangles
// int solution(vector<string> &A) {
//     int N = A.size();
//     int M = A[0].size();
    
//     // Precompute the length of vertical and horizontal cultivable areas starting from each cell
//     vector<vector<int>> vertical(N, vector<int>(M, 0));
//     vector<vector<int>> horizontal(N, vector<int>(M, 0));
    
//     // Calculate vertical lengths
//     for (int j = 0; j < M; ++j) {
//         for (int i = N - 1; i >= 0; --i) {
//             if (A[i][j] == '.') {
//                 vertical[i][j] = 1 + (i + 1 < N ? vertical[i + 1][j] : 0);
//             }
//         }
//     }
    
//     // Calculate horizontal lengths
//     for (int i = 0; i < N; ++i) {
//         for (int j = M - 1; j >= 0; --j) {
//             if (A[i][j] == '.') {
//                 horizontal[i][j] = 1 + (j + 1 < M ? horizontal[i][j + 1] : 0);
//             }
//         }
//     }
    
//     // To find the maximum area with at most two rectangles
//     int max_single_area = 0;
//     vector<pair<int, int>> vertical_areas; // (length, start index)
//     vector<pair<int, int>> horizontal_areas; // (length, start index)
    
//     // Collect all vertical areas
//     for (int j = 0; j < M; ++j) {
//         for (int i = 0; i < N; ++i) {
//             if (vertical[i][j] > 0) {
//                 vertical_areas.push_back({vertical[i][j], i * M + j});
//                 max_single_area = max(max_single_area, vertical[i][j]);
//             }
//         }
//     }
    
//     // Collect all horizontal areas
//     for (int i = 0; i < N; ++i) {
//         for (int j = 0; j < M; ++j) {
//             if (horizontal[i][j] > 0) {
//                 horizontal_areas.push_back({horizontal[i][j], i * M + j});
//                 max_single_area = max(max_single_area, horizontal[i][j]);
//             }
//         }
//     }
    
//     // Function to check if two areas overlap
//     auto overlap = [&](int start1, int length1, bool vertical1, int start2, int length2, bool vertical2) {
//         int r1 = start1 / M, c1 = start1 % M;
//         int r2 = start2 / M, c2 = start2 % M;
        
//         if (vertical1 && vertical2) {
//             return c1 == c2 && max(r1, r2) < min(r1 + length1, r2 + length2);
//         } else if (!vertical1 && !vertical2) {
//             return r1 == r2 && max(c1, c2) < min(c1 + length1, c2 + length2);
//         } else if (vertical1 && !vertical2) {
//             return c1 >= c2 && c1 < c2 + length2 && r2 >= r1 && r2 < r1 + length1;
//         } else {
//             return c2 >= c1 && c2 < c1 + length1 && r1 >= r2 && r1 < r2 + length2;
//         }
//     };
    
//     int max_combined_area = 0;
    
//     // Evaluate combinations of vertical and horizontal areas
//     for (const auto& v : vertical_areas) {
//         for (const auto& h : horizontal_areas) {
//             if (!overlap(v.second, v.first, true, h.second, h.first, false)) {
//                 max_combined_area = max(max_combined_area, v.first + h.first);
//             }
//         }
//     }
    
//     // Evaluate combinations of two vertical areas
//     for (size_t i = 0; i < vertical_areas.size(); ++i) {
//         for (size_t j = i + 1; j < vertical_areas.size(); ++j) {
//             if (!overlap(vertical_areas[i].second, vertical_areas[i].first, true, vertical_areas[j].second, vertical_areas[j].first, true)) {
//                 max_combined_area = max(max_combined_area, vertical_areas[i].first + vertical_areas[j].first);
//             }
//         }
//     }
    
//     // Evaluate combinations of two horizontal areas
//     for (size_t i = 0; i < horizontal_areas.size(); ++i) {
//         for (size_t j = i + 1; j < horizontal_areas.size(); ++j) {
//             if (!overlap(horizontal_areas[i].second, horizontal_areas[i].first, false, horizontal_areas[j].second, horizontal_areas[j].first, false)) {
//                 max_combined_area = max(max_combined_area, horizontal_areas[i].first + horizontal_areas[j].first);
//             }
//         }
//     }
    
//     return max(max_single_area, max_combined_area);
// }


// int main() {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);

//     // vector<string> A = {".##..", ".#.#.", ".....", "##..#"};
//     vector<string> A = {"###..", ".....", "###.#"};

//     cout << solution(A) << "\n";
// }