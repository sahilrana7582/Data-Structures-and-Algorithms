class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long mod = 1e9 + 7;

        vector<vector<pair<int, long long>>> adj(n);
        for (auto& road : roads) {
            int u = road[0];
            int v = road[1];
            int w = road[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        vector<long long> dist(n, LONG_MAX);

        dist[0] = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>
            pq;

            pq.push({0, 0});
            vector<long long> path(n, 0);
            path[0] = 1;


            while(!pq.empty()){
                pair<long long, int> p = pq.top();
                int node = p.second;
                long long currDist = p.first;
                pq.pop();


                for(auto &nei:adj[node]){
                    int newNode = nei.first;
                    long long newDist = nei.second;

                    if(dist[newNode] > newDist + currDist){
                        dist[newNode] = newDist + currDist;
                        pq.push({dist[newNode], newNode});
                        path[newNode] = (path[node])%mod;

                    }else if(dist[newNode] == newDist + currDist){
                        path[newNode] = (path[newNode] + path[node])%mod;
                    }
                }




            }


            return path[n - 1];
    }
};