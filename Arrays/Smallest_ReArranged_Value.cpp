class Solution {
    public:
        string solve(vector<int>& freq, long long num) {
            string ans;
    
            if (num > 0) {
                for (int i = 1; i < 10; i++) {
                    if (freq[i] > 0) {
                        ans.push_back(i + '0');
                        freq[i]--;
                        break;
                    }
                }
    
                for (int i = 0; i < 10; i++) {
                    while (freq[i] > 0) {
                        ans.push_back(i + '0');
                        freq[i]--;
                    }
                }
            } else {
                for (int i = 9; i >= 0; i--) {
                    while (freq[i] > 0) {
                        ans.push_back(i + '0');
                        freq[i]--;
                    }
                }
            }
    
            return ans;
        }
    
        long long smallestNumber(long long num) {
            if (num == 0) return 0;
    
            long long absNum = abs(num);
            vector<int> freq(10, 0);
    
            for (char ch : to_string(absNum)) {
                freq[ch - '0']++;
            }
    
            string ans = solve(freq, num);
            long long result = stoll(ans);
    
            return num < 0 ? -result : result;
        }
    };
    