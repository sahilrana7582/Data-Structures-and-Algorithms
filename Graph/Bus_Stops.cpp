class Solution {
    public:
        int numBusesToDestination(vector<vector<int>>& routes, int source,
                                  int target) {
            if (source == target)
                return 0;
    
            unordered_map<int, vector<int>> stopToRoutes;
            int n = routes.size();
    
            for (int i = 0; i < n; i++) {
                for (int stop : routes[i]) {
                    stopToRoutes[stop].push_back(i);
                }
            }
    
            vector<bool> routeVisited(n, false);
            unordered_set<int> stopVisited;
            queue<pair<int, int>> q; // {stop, busesTaken}
    
            q.push({source, 0});
            stopVisited.insert(source);
    
            while (!q.empty()) {
                auto [stop, buses] = q.front();
                q.pop();
    
                if (stop == target)
                    return buses;
    
                for (int route : stopToRoutes[stop]) {
                    if (routeVisited[route])
                        continue;
                    routeVisited[route] = true;
    
                    for (int nextStop : routes[route]) {
                        if (!stopVisited.count(nextStop)) {
                            stopVisited.insert(nextStop);
                            q.push({nextStop, buses + 1});
                        }
                    }
                }
            }
    
            return -1;
        }
    };