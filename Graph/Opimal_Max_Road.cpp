class Solution {
    public:
        long long maximumImportance(int n, vector<vector<int>>& roads) {
            unordered_map<int, int> freqConn;
    
            for (auto &road : roads) {
                freqConn[road[0]] += 1;
                freqConn[road[1]] += 1;
            }
    
            priority_queue<pair<int, int>> pq;
    
            for (auto [key, val] : freqConn) {
                pq.push({val, key});
            }
    
            unordered_map<int, int> num;
    
            int temp = n;
    
            long long res = 0;
    
            for (auto &r : roads) {
                res += num[r[0]] + num[r[1]];
            }
    
            return res;
        }
    };
    