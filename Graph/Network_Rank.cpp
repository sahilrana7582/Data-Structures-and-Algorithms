class Solution {
    public:
        int maximalNetworkRank(int n, vector<vector<int>>& roads) {
            vector<int> degree(n, 0);
            int ans = INT_MIN;
            unordered_set<string> st;
    
            for (vector<int> r : roads) {
                int a = r[0];
                int b = r[1];
                degree[a]++;
                degree[b]++;
                if (a > b) swap(a, b);
                st.insert(to_string(a) + "_" + to_string(b));
            }
    
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    int rank = degree[i] + degree[j];
                    int a = i, b = j;
                    if (a > b) swap(a, b);
                    string key = to_string(a) + "_" + to_string(b);
                    if (st.count(key)) {
                        rank--;  
                    }
                    ans = max(ans, rank);
                }
            }
    
            return ans;
        }
    };
    