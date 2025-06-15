class Solution {
    public:
        int maxDiff(int num) {
            string s = to_string(num);
            int maxVal = num, minVal = num;
    
            for (char x = '0'; x <= '9'; x++) {
                for (char y = '0'; y <= '9'; y++) {
                    string t = s;
                    for (char& c : t) {
                        if (c == x) {
                            c = y;
                        }
                    }
    
                    if (t[0] == '0')
                        continue;
    
                    int val = stoi(t);
    
                    maxVal = max(maxVal, val);
                    minVal = min(minVal, val);
                }
            }
    
            return maxVal - minVal;
        }
    };




    // ---------------- GREEDY --------------------
    class Solution {
        public:
            int maxDiff(int num) {
                string s = to_string(num);
                int maxVal = num, minVal = num;
        
                for (char x = '0'; x <= '9'; x++) {
                    string t = s;
                    char y = (x == t[0]) ? '1' : '0'; 
        
                    for (char &ch : t) {
                        if (ch == x) ch = y;
                    }
        
                    if (t[0] == '0') continue;  
        
                    int val = stoi(t);
                    minVal = min(minVal, val);
                }
        
                for (char x = '0'; x <= '9'; x++) {
                    string t = s;
                    for (char &ch : t) {
                        if (ch == x) ch = '9';
                    }
        
                    if (t[0] == '0') continue;
        
                    int val = stoi(t);
                    maxVal = max(maxVal, val);
                }
        
                return maxVal - minVal;
            }
        };
        