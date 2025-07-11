class Solution {
    public:
        vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
            vector<set<int>> ancestors(n); 
            vector<int> indegree(n);
            vector<vector<int>> adj(n);
    
            for (auto& edge : edges) {
                int u = edge[0], v = edge[1];
                adj[u].push_back(v);
                indegree[v]++;
            }
    
            queue<int> q;
            for (int i = 0; i < n; i++) {
                if (indegree[i] == 0) q.push(i);
            }
    
            while (!q.empty()) {
                int node = q.front();
                q.pop();
    
                for (int nei : adj[node]) {
                    ancestors[nei].insert(node);
    
                    for (int a : ancestors[node]) {
                        ancestors[nei].insert(a);
                    }
    
                    indegree[nei]--;
                    if (indegree[nei] == 0) q.push(nei);
                }
            }
    
            vector<vector<int>> res(n);
            for (int i = 0; i < n; i++) {
                res[i] = vector<int>(ancestors[i].begin(), ancestors[i].end());
            }
    
            return res;
        }
    };
    