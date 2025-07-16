class Solution {
    public:
        vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
            vector<vector<pair<int, int>>> adj(n); 
            vector<int> res;
    
            for (int i = 0; i < n - 1; i++) {
                adj[i].push_back({i + 1, 1});
            }
    
            for (int i = 0; i < queries.size(); i++) {
                int u = queries[i][0];
                int v = queries[i][1];
    
                adj[u].push_back({v, 1});
    
                vector<int> dist(n, INT_MAX);
                dist[0] = 0;
    
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
                pq.push(make_pair(0, 0));
    
                while (!pq.empty()) {
                    pair<int, int> current = pq.top();
                    pq.pop();
    
                    int d = current.first;
                    int node = current.second;
    
                    if (d > dist[node]) continue;
    
                    for (int j = 0; j < adj[node].size(); j++) {
                        int neighbor = adj[node][j].first;
                        int weight = adj[node][j].second;
    
                        if (dist[neighbor] > dist[node] + weight) {
                            dist[neighbor] = dist[node] + weight;
                            pq.push(make_pair(dist[neighbor], neighbor));
                        }
                    }
                }
    
                res.push_back(dist[n - 1]);
            }
    
            return res;
        }
    };
    