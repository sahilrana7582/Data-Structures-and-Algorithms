class Solution {
public:
    int solve(int node, unordered_map<int, bool>& mpp,
              vector<vector<int>>& adj, vector<bool>& vis) {

        vis[node] = true;
        int ans = 0;

        for (auto nei : adj[node]) {
            if (!vis[nei]) {
                int res = solve(nei, mpp, adj, vis);
                if (res) {
                    ans += res + 2; // +2 for the round trip
                }
            }
        }

        if(mpp[node]){
            ans += 1;
        }


        return ans != 0 ? ans : 0;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        unordered_map<int, bool> mpp;
        for (int i = 0; i < hasApple.size(); i++) {
            mpp[i] = hasApple[i];
        }

        int numOfApp = 0;
        for(bool a : hasApple){
            if(a){
                numOfApp += 1;
            }
        }

        vector<bool> vis(n, false);
        int ans = max(0, solve(0, mpp, adj, vis));
        

        return ans - numOfApp;
        
    
    }
};
