// 787. Cheapest Flights Within K Stops
// LeetCode : https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include<bits/stdc++.h>
using namespace std;


// method-1 : OPTIMAL : dijkstra's algorithm using priority queue
/*
TC : O(E * logV)
SC : O(V + E)
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // prepare adj list : {city, cost}
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // min-heap : {stops, {cost, city}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        vector<int> price(n, 1e9);
        price[src] = 0;
        pq.push({0, {0, src}});
        while(!pq.empty()) {
            int stops = pq.top().first;
            int cost = pq.top().second.first;
            int city = pq.top().second.second;
            pq.pop();

            if(stops > k) break;

            for(auto nbr : adj[city]) {
                int adjCity = nbr.first;
                int adjCost = nbr.second;

                if(cost + adjCost < price[adjCity] && stops <= k) {
                    price[adjCity] = cost + adjCost;
                    pq.push({stops+1, {price[adjCity], adjCity}});
                }
            }
        }

        if(price[dst] != 1e9) return price[dst];
        return -1;
    }
};


// method-0 : BRUTE FORCE : dijkstra's algorithm using queue
/*
TC : O(E)
SC : O(V + E)
*/
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // prepare adj list : {city, cost}
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        queue<pair<int, pair<int, int>>> q; // {stops, {cost, city}}
        vector<int> price(n, 1e9);
        price[src] = 0;
        q.push({0, {0, src}});
        while(!q.empty()) {
            int stops = q.front().first;
            int cost = q.front().second.first;
            int city = q.front().second.second;
            q.pop();

            if(stops > k) continue;

            for(auto nbr : adj[city]) {
                int adjCity = nbr.first;
                int adjCost = nbr.second;

                if(cost + adjCost < price[adjCity] && stops <= k) {
                    price[adjCity] = cost + adjCost;
                    q.push({stops+1, {price[adjCity], adjCity}});
                }
            }
        }

        if(price[dst] != 1e9) return price[dst];
        return -1;
    }
};


int main() {
    
    return 0;
}