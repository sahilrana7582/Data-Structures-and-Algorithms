class Solution {
    public:
        void solve(int ind, vector<int> &c, int &k, vector<int> &dist, int &ans){
            if (ind >= c.size()) {
                ans = min(ans, *max_element(dist.begin(), dist.end()));
                return;
            }
    
            for (int j = 0; j < k; j++) {
                dist[j] += c[ind];
                solve(ind + 1, c, k, dist, ans);
                dist[j] -= c[ind];
            }
        }
    
        int distributeCookies(vector<int>& c, int k) {
            vector<int> dis(k, 0);
            int ans = INT_MAX;
            solve(0, c, k, dis, ans);
            return ans;
        }
    };
    