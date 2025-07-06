class Solution {
    public:
        vector<int> getOrder(vector<vector<int>>& tasks) {
            int n = tasks.size();
            vector<int> ans;
    
            vector<tuple<int, int, int>> indexedTasks;
            for (int i = 0; i < n; ++i) {
                indexedTasks.push_back({tasks[i][0], tasks[i][1], i});
            }
    
            sort(indexedTasks.begin(), indexedTasks.end());
    
            priority_queue<pair<int, int>, vector<pair<int, int>>,
                           greater<pair<int, int>>>
                pq;
    
            long long time = 0;
            int i = 0;
    
            while (i < n || !pq.empty()) {
                while (i < n && get<0>(indexedTasks[i]) <= time) {
                    pq.push({get<1>(indexedTasks[i]), get<2>(indexedTasks[i])});
                    ++i;
                }
    
                if (!pq.empty()) {
    
                    auto [procTime, idx] = pq.top();
                    pq.pop();
                    ans.push_back(idx);
                    time += procTime;
                } else {
    
                    time = get<0>(indexedTasks[i]);
                }
            }
    
            return ans;
        }
    };