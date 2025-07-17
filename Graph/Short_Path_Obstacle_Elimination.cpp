class Solution {
    public:
        struct State {
            int row, col, steps, k_left;
        };
    
        int shortestPath(vector<vector<int>>& grid, int k) {
            int n = grid.size(), m = grid[0].size();
            queue<State> q;
            vector<vector<vector<bool>>> vis(
                n, vector<vector<bool>>(m, vector<bool>(k + 1, false)));
    
            q.push({0, 0, 0, k});
            vis[0][0][k] = true;
    
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
    
            while (!q.empty()) {
                auto [r, c, steps, rem_k] = q.front();
                q.pop();
    
                if (r == n - 1 && c == m - 1)
                    return steps;
    
                for (int i = 0; i < 4; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];
    
                    if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                        int new_k = rem_k - grid[nr][nc];
    
                        if (new_k >= 0 && !vis[nr][nc][new_k]) {
                            vis[nr][nc][new_k] = true;
                            q.push({nr, nc, steps + 1, new_k});
                        }
                    }
                }
            }
    
            return -1;
        }
    };
    