class Solution {
    public:
        void solve(int i, vector<int> &vis, vector<vector<pair<int, int>>> &adj, int &ans){
    
            vis[i] = 1;
    
            for(pair<int, int> p : adj[i]){
                int nextNode = p.first;
                int score = p.second;
                ans = min(ans, score);
                if(vis[nextNode] == -1){
                    solve(nextNode, vis, adj, ans);
                }
            }
        }
        int minScore(int n, vector<vector<int>>& roads) {
    
            int ans = INT_MAX;
            vector<vector<pair<int, int>>> adj(n + 1);
            for (auto& road : roads) {
                int u = road[0], v = road[1], w = road[2];
                adj[u].push_back({v, w});
                adj[v].push_back({u, w});
            }
    
            vector<int> vis(n + 1, -1);
    
            solve(1, vis, adj, ans);
    
    
    
            return ans;
        }
    };