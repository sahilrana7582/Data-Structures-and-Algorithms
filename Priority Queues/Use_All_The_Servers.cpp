class Solution {
    public:
        vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
            int n = servers.size();
            int m = tasks.size();
    
            vector<int> ans(m, 0);
    
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> freeServers;
            priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<tuple<long long, int, int>>> busyServers;
    
            for (int i = 0; i < n; i++) {
                freeServers.push({servers[i], i});
            }
    
            long long currTime = 0;
            int idx = 0;
    
            while (idx < m) {
                currTime = max(currTime, (long long)idx); 
    
                while (!busyServers.empty() && get<0>(busyServers.top()) <= currTime) {
                    auto [freeTime, weight, index] = busyServers.top();
                    busyServers.pop();
                    freeServers.push({weight, index});
                }
    
                if (freeServers.empty()) {
                    currTime = get<0>(busyServers.top());
                    continue;
                }
    
                auto [weight, index] = freeServers.top();
                freeServers.pop();
    
                long long freeTime = currTime + tasks[idx];
                busyServers.push({freeTime, weight, index});
                ans[idx] = index;
                idx += 1;
            }
    
            return ans;
        }
    };
    