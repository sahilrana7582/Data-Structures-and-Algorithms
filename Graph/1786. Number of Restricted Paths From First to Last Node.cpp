class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {

        const int mod = 1e9 + 7;
        

        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<long long> dist(n + 1, LONG_MAX);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

        dist[n] = 0;
        pq.push({0, n});

        while(!pq.empty()){
            int node = pq.top().second;
            long long currDist = pq.top().first;
            pq.pop();

            if(currDist > dist[node]) continue;

            for(auto &nei:adj[node]){
                int newNode = nei.first;
                int newDist = nei.second;

                if(newDist + currDist < dist[newNode]){
                    dist[newNode] = newDist + currDist;
                    pq.push({dist[newNode], newNode});
                }
            }
        }




        vector<int> dp(n + 1, -1);
        function<int(int)> dfs = [&](int node) -> int {

            if(node == 1){
                return 1;
            }

            if(dp[node] != -1){
                return dp[node];
            }



            int ways = 0;
            for(auto &nei : adj[node]){
                if(dist[node] < dist[nei.first]){
                    ways = (ways + dfs(nei.first)) % mod;
                }
            }
            return dp[node] = ways;
        };

        return dfs(n);

    }
};





