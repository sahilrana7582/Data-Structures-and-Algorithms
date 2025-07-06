

class Solution {
    public:
        class UnionFind {
        public:
            vector<int> parent;
            vector<int> rank;
    
            UnionFind(int n) {
                parent.resize(n);
                rank.resize(n, 0);
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
    
            bool unionT(int x, int y) {
                int rootX = find(x);
                int rootY = find(y);
    
                if (rootX == rootY) {
                    return false;
                }
    
                if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                } else if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                } else {
                    parent[rootY] = rootX;
                    rank[rootX] += 1;
                }
    
                return true;
            }
        };
    
        int krushalAlgo(int n, vector<vector<int>>& edges, int edExclude,
                        int edInclude) {
            int sum = 0;
            UnionFind uf(n);
    
            if (edInclude != -1) {
                int u = edges[edInclude][0];
                int v = edges[edInclude][1];
                int wt = edges[edInclude][2];
    
                uf.unionT(u, v);
                sum += wt;
            }
    
            for (int i = 0; i < edges.size(); i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
    
                if (i == edExclude) {
                    continue;
                }
    
                if (uf.unionT(u, v)) {
                    sum += wt;
                }
            }
    
    
            for (int i = 0; i < n; i++) {
                if(uf.find(i) != uf.find(0)){
                    return INT_MAX;
                }
            }
    
            return sum;
        }
    
        vector<vector<int>>
        findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
            vector<vector<int>> ans;
    
            for (int i = 0; i < edges.size(); i++) {
                edges[i].push_back(i);
            }
    
            sort(edges.begin(), edges.end(),
                 [](const vector<int>& a, const vector<int>& b) {
                     return a[2] < b[2];
                 });
    
            int mstW = krushalAlgo(n, edges, -1, -1);
    
            cout<<mstW;
    
            vector<int> critical;
            vector<int> sudoCritical;
    
            for (int i = 0; i < edges.size(); i++) {
                if (krushalAlgo(n, edges, i, -1) > mstW) {
                    critical.push_back(edges[i][3]);
                } else if (krushalAlgo(n, edges, -1, i) == mstW) {
                    sudoCritical.push_back(edges[i][3]);
                }
            }
    
            return {critical, sudoCritical};
        }
    };