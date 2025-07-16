class Solution {
    public:
        int findChampion(int n, vector<vector<int>>& edges) {
    
            vector<vector<int>> adj(n);
            vector<int> inorder(n);
    
    
            for(auto edge : edges){
                adj[edge[0]].push_back(edge[1]);
                inorder[edge[1]] += 1;
            }
    
    
            int champion = -1;
    
            for(int i=0; i<inorder.size(); i++){
                if(inorder[i] == 0){
                    if(champion == -1){
                        champion = i;
                    }else{
                        return -1;
                    }
                }
            }
    
    
            vector<bool> vis(n, false);
            queue<int> q;
            q.push(champion);
            int cnt = 1;
            vis[champion] = true;
    
    
            while(!q.empty()){
                int node = q.front();
                q.pop();
    
                for(auto nei : adj[node]){
                    if(!vis[nei]){
                        vis[nei] = true;
                        q.push(nei);
                        cnt += 1;
                    }
                }
            }
    
    
    
            return cnt == n ? champion : -1;
            
        }
    };