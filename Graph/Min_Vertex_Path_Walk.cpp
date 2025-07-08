class Solution {
    public:
        class UnionFind {
        public:
            vector<int> parent;
            vector<int> mask; 
    
            UnionFind(int n) {
                parent.resize(n);
                mask.resize(n, -1); 
                for (int i = 0; i < n; i++) {
                    parent[i] = i;
                }
            }
    
            int find(int x) {
                if (parent[x] != x) {
                    parent[x] = find(parent[x]);
                }
                return parent[x];
            }
    
            void unite(int x, int y, int wg){
                int parX = find(x);
                int parY = find(y);
    
                if(parX == parY){
                    mask[parX] &= wg;
                }else{
                    parent[parX] = parY;
    
                    mask[parY] = (mask[parX] & mask[parY] & wg);
    
                }
            }
        } ;
        vector<int> minimumCost(int n, vector<vector<int>>& edges,vector<vector<int>>& query) {
            int sizeAns = query.size();
            vector<int> ans(sizeAns, -1);
    
            UnionFind uf(n);
    
            for(auto edge : edges){
                uf.unite(edge[0], edge[1], edge[2]);
            }
    
            for(int i=0; i<query.size(); i++){
                int parX = uf.find(query[i][0]); 
                int parY = uf.find(query[i][1]); 
    
                if(parX == parY){
                    ans[i] = uf.mask[parX];
                }
            }
    
            return ans;
        }
    };