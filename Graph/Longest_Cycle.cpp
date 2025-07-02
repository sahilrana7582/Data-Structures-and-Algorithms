class Solution {
    public:
        void dfs(int node, int step, vector<int>& edges, vector<int>& vis,
                 vector<int>& timeIn, int& ans) {
    
            vis[node] = 1;
            timeIn[node] = step;
    
            int next = edges[node];
            if (next != -1) {
                if (vis[next] == 0) {
                    dfs(next, step + 1, edges, vis, timeIn, ans);
                } else if (timeIn[next] != -1) {
                    ans = max(ans, step - timeIn[next] + 1);
                }
            }
    
            timeIn[node] = -1;
        }
        int longestCycle(vector<int>& edges) {
    
            int ans = 0;
            int n = edges.size();
            vector<int> vis(n, 0);
            vector<int> currPath(n, -1);
    
            for (int i = 0; i < n; i++) {
                if (vis[i] == 0) {
                    dfs(i, 0, edges, vis, currPath, ans);
                }
            }
    
            return (ans == 0) ? -1 : ans;
        }
    };