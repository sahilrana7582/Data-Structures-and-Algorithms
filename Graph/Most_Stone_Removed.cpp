class Solution {
    public:
        void dfs(int i, vector<vector<int>> &s, vector<bool> &vis){
            vis[i] = true;
    
            for(int u = 0; u<s.size(); u++){
                if(!vis[u] && (s[i][0] == s[u][0] || s[i][1] == s[u][1])){
                    dfs(u, s, vis);
                }
            }
        }
        int removeStones(vector<vector<int>>& s) {
            int n = s.size();
            vector<bool> vis(n, false);
            int components = 0;
    
            for(int i = 0; i<n; i++){
                if(!vis[i]){
                    dfs(i, s, vis);
                    components += 1;
                }
            }
    
    
            return n - components;
        }
    };