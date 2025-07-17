class Solution {
    public:
        int minimumObstacles(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
    
            vector<vector<int>> dist(n, vector<int>(m, 1e9));
            priority_queue<pair<int, pair<int, int>>, 
                           vector<pair<int, pair<int, int>>>, 
                           greater<>> pq;
    
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
    
            dist[0][0] = 0;
            pq.push({0, {0, 0}});
    
            while (!pq.empty()) {
                auto [currObs, cell] = pq.top(); pq.pop();
                int row = cell.first, col = cell.second;
    
                if (row == n - 1 && col == m - 1) {
                    return currObs;
                }
    
                for (int i = 0; i < 4; ++i) {
                    int newRow = row + dr[i];
                    int newCol = col + dc[i];
    
                    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m) {
                        int newObs = currObs + grid[newRow][newCol];
                        if (newObs < dist[newRow][newCol]) {
                            dist[newRow][newCol] = newObs;
                            pq.push({newObs, {newRow, newCol}});
                        }
                    }
                }
            }
    
            return -1; 
        }
    };
    