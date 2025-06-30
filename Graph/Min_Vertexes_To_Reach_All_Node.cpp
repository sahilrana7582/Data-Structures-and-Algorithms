class Solution {
    public:
        vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
            vector<int> ans(n, 0);
    
            for(auto ed : e){
                int u = ed[0];
                int v = ed[1];
    
                ans[v] += 1;
            }
    
    
            vector<int> res;
    
            for(int i=0; i<n; i++){
                if(ans[i] == 0){
                    res.push_back(i);
                }
            }
    
    
            return res;
            
        }
    };