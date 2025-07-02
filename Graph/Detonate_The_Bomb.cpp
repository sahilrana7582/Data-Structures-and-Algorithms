class Solution {
    public:
        bool dis(int x1, int y1, int x2, int y2, long long r) {
            long long dx = x1 - x2;
            long long dy = y1 - y2;
            return dx * dx + dy * dy <= r * r;
        }
    
        int dfs(int idx, unordered_map<int, vector<int>>& mpp, vector<int>& vis) {
            vis[idx] = 1;
            int count = 1;  
    
            for (int nei : mpp[idx]) {
                if (vis[nei] == -1) {
                    count += dfs(nei, mpp, vis);
                }
            }
            return count;
        }
    
        int maximumDetonation(vector<vector<int>>& bombs) {
            unordered_map<int, vector<int>> mpp;
            int n = bombs.size();
            int maxAns = 0;
    
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;
                    if (dis(bombs[i][0], bombs[i][1], bombs[j][0], bombs[j][1], bombs[i][2])) {
                        mpp[i].push_back(j);
                    }
                }
            }
    
            for (int i = 0; i < n; i++) {
                vector<int> vis(n, -1);
                int count = dfs(i, mpp, vis);
                maxAns = max(maxAns, count);
            }
    
            return maxAns;
        }
    };
    