class Solution {
    public:
        int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
            vector<vector<int>> adj(n + 1);
            vector<int> indegree(n + 1, 0);
            vector<int> minTime(n + 1, 0); 
    
            for (auto& r : relations) {
                adj[r[0]].push_back(r[1]);
                indegree[r[1]]++;
            }
    
            queue<int> q; 
    
            for (int i = 1; i <= n; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                    minTime[i] = time[i - 1]; 
                }
            }
    
            while (!q.empty()) {
                int node = q.front();
                q.pop();
    
                for (int nei : adj[node]) {
                    minTime[nei] = max(minTime[nei], minTime[node] + time[nei - 1]);
    
                    if (--indegree[nei] == 0) {
                        q.push(nei);
                    }
                }
            }
    
            return *max_element(minTime.begin(), minTime.end());
        }
    };
    