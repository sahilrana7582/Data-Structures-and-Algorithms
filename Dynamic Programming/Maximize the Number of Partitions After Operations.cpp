class Solution {
    public:
        int n;
    
        int solve(int idx, int mask, bool change, string &s, int k,
                  vector<vector<unordered_map<int, int>>> &dp) {
            if (idx == n) return 0;
    
            if (dp[idx][change].count(mask)) return dp[idx][change][mask];
    
            int charIndex = s[idx] - 'a';
            int newMask = mask | (1 << charIndex);
            int bits = __builtin_popcount(newMask);
    
            int res = 0;
    
            if (bits > k) {
                res = 1 + solve(idx + 1, (1 << charIndex), change, s, k, dp);
            } else {
                res = solve(idx + 1, newMask, change, s, k, dp);
            }
    
            if (change) {
                for (int i = 0; i < 26; i++) {
                    int changedMask = mask | (1 << i);
                    int changedBits = __builtin_popcount(changedMask);
                    if (changedBits > k) {
                        res = max(res, 1 + solve(idx + 1, (1 << i), false, s, k, dp));
                    } else {
                        res = max(res, solve(idx + 1, changedMask, false, s, k, dp));
                    }
                }
            }
    
            return dp[idx][change][mask] = res;
        }
    
        int maxPartitionsAfterOperations(string s, int k) {
            n = s.size();
    
            vector<vector<unordered_map<int, int>>> dp(n + 1, vector<unordered_map<int, int>>(2));
            return solve(0, 0, true, s, k, dp) + 1;
        }
    };
    