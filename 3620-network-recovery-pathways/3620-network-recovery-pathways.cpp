#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        vector<int> indegree(n, 0);
        
        int max_cost = 0;
        // 1. Build graph with only online nodes
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], c = edge[2];
            if (online[u] && online[v]) {
                adj[u].push_back({v, c});
                indegree[v]++;
                max_cost = max(max_cost, c);
            }
        }
        
        // 2. Precompute Topological Sort
        vector<int> topo;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) q.push(i);
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);
            for (auto& edge : adj[u]) {
                int v = edge.first;
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        // 3. Binary Search on the maximum possible "minimum edge score"
        int low = 0, high = max_cost;
        int ans = -1;
        const long long INF = 1e18; 
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            vector<long long> dist(n, INF);
            dist[0] = 0;
            
            // DAG Shortest Path
            for (int u : topo) {
                if (dist[u] != INF) {
                    for (auto& edge : adj[u]) {
                        int v = edge.first;
                        int c = edge.second;
                        if (c >= mid) {
                            dist[v] = min(dist[v], dist[u] + (long long)c);
                        }
                    }
                }
            }
            
            if (dist[n-1] <= k) {
                ans = mid;       // Valid path found, try to find a larger minimum
                low = mid + 1;
            } else {
                high = mid - 1;  // Invalid path, decrease the threshold
            }
        }
        
        return ans;
    }
};