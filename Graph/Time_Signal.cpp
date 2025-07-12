class Solution {
    public:
        int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
            vector<vector<int>> adj(n + 1);
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
    
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq;
            pq.push({0, 1});
    
            unordered_map<int, vector<int>> visits;
    
            int cnt = 0;
    
            while (!pq.empty()) {
                auto [currTime, node] = pq.top();
                pq.pop();
    
                if (find(visits[node].begin(), visits[node].end(), currTime) !=
                    visits[node].end())
                    continue;
    
                if (visits[node].size() == 2)
                    continue;
    
                visits[node].push_back(currTime);
    
                if (node == n) {
                    cnt += 1;
                    if (cnt == 2)
                        return currTime;
                }
    
                for (int nei : adj[node]) {
                    int t = currTime;
    
                    int elapsed = t;
                    bool isGreen = true;
    
                    while (elapsed >= change) {
                        elapsed -= change;
                        isGreen = !isGreen;
                    }
    
                    if (!isGreen) {
                        int wait = change - elapsed;
                        t += wait;
                    }
    
                    t += time;
                    pq.push({t, nei});
                }
            }
    
            return -1;
        }
    };
    