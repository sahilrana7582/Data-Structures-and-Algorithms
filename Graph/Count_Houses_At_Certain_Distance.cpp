class Solution {
    public:
        vector<int> countOfPairs(int n, int x, int y) {
            vector<vector<int>> graph(n + 1);
            vector<int> ans(n, 0);
    
            for (int i = 1; i < n; i++) {
                graph[i].push_back(i + 1);
                graph[i + 1].push_back(i);
            }
            graph[x].push_back(y);
            vector<int> dist(n + 1, 0);
    
            graph[y].push_back(x);
    
            for (int start = 1; start <= n; start++) {
                queue<pair<int, int>> q;
                q.push({start, 0});
                vector<int> vis(n + 1, -1);
                vis[start] = 1;
    
                while (!q.empty()) {
                    int node = q.front().first;
                    int dis = q.front().second;
                    q.pop();
    
                    dist[dis] += 1;
    
                    for (auto nei : graph[node]) {
                        if (vis[nei] == -1) {
                            vis[nei] = 1;
                            q.push({nei, dis + 1});
                        }
                    }
                }
            }
    
            return vector<int>(dist.begin() + 1, dist.end());
    
        }
    };
    