class Solution {
    public:
        void solve(int node, int& size, vector<int>& vis,
                   vector<vector<int>>& adj) {
    
            vis[node] = 1;
            size += 1;
    
            for (auto nei : adj[node]) {
                if (vis[nei] == -1) {
                    solve(nei, size, vis, adj);
                }
            }
        }
        long long countPairs(int n, vector<vector<int>>& edges) {
            vector<vector<int>> adj(n);
            unordered_map<int, int> mpp;
            vector<int> vis(n, -1);
    
            for (auto e : edges) {
                int u = e[0];
                int v = e[1];
    
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            int strong = 0;
    
            for (int i = 0; i < n; i++) {
                if (vis[i] == -1) {
                    int size = 0;
                    solve(i, size, vis, adj);
                    mpp[strong] = size;
                    strong += 1;
                }
            }
    
            long long ans = 0;
            long long remaining = n;
    
            for (auto [key, val] : mpp) {
                ans += (long long)val * (remaining - val);
                remaining -= val;
            }
    
            return ans;
        }
    };