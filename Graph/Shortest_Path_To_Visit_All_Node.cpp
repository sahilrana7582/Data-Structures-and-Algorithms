class Solution {
    public:
        int shortestPathLength(vector<vector<int>>& graph) {
    
            int n = graph.size();
            queue<pair<int, pair<int, int>>> q;
            vector<vector<bool>> visited(n, vector<bool>(1 << n, false));
    
            for (int i = 0; i < n; i++) {
                q.push({i, {1 << i, 0}});
                visited[i][1 << i] = true;
            }
    
            while (!q.empty()) {
                auto [node, p] = q.front();
                q.pop();
                int mask = p.first;
                int dist = p.second;
    
                if (mask == (1 << n) - 1) {
                    return dist;
                }
    
                for (auto neighbor : graph[node]) {
                    int newMask =  (1 << neighbor) | mask;
    
                    if (!visited[neighbor][newMask]) {
                        visited[neighbor][newMask] = true;
                        q.push({neighbor, {newMask, dist + 1}});
                    }
                }
            }
    
            return 0;
        }
    };