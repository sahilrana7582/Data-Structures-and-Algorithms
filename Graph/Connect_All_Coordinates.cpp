class Solution {
    public:
        int minCostConnectPoints(vector<vector<int>>& points) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
            int n = points.size();
            vector<int> vis(n, -1);
    
            int tot = 0;
    
            pq.push({0, 0});
    
            while (!pq.empty()) {
                int dist = pq.top().first;
                int idx = pq.top().second;
                pq.pop();
    
                if(vis[idx] == -1){
                    tot += dist;
                    vis[idx] = 1;
                    for(int i = 0; i<n; i++){
                        if(i != idx && vis[i] == -1){
                            int x1 = points[idx][0];
                            int y1 = points[idx][1];
                            int x2 = points[i][0];
                            int y2 = points[i][1];
    
                            int newDist = abs(x1 - x2) + abs(y1 - y2);
    
                            pq.push({newDist, i});
    
                        }
                    }
                }
    
            }
    
            return tot;
        }
    };