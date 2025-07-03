class Solution {
    public:
        bool dfs(int node, vector<vector<int>> &e, vector<bool> &vis, vector<bool> &path, vector<bool> &safe){
    
            vis[node] = true;
            path[node] = true;
    
            bool isSafe = true;
    
            for(auto nei : e[node]){
    
                if(safe[nei]){
                   continue; 
                }else{
                    if(!vis[nei]){
                        isSafe = isSafe && dfs(nei, e, vis, path, safe);
                    }else{
                        if(path[node]){
                            isSafe = false;
                        }
                    }
                }
            }
    
            safe[node] = isSafe;
            return isSafe;
    
        }
        vector<int> eventualSafeNodes(vector<vector<int>>& e) {
            int n = e.size();
            vector<bool> vis(n, false);
            vector<bool> path(n, false);
            vector<bool> safe(n, false);
    
            vector<int> ans;
    
    
            for(int i=0; i<n; i++){
                if(!vis[i]){
                    dfs(i, e, vis, path, safe);
                }
            }
    
            for(int i=0; i<safe.size(); i++){
                if(safe[i]){
                    ans.push_back(i);
                }
            }
    
    
            return ans;
    
            
        }
    };