class Solution {
    public:
        int minMaxDifference(int num) {
            string s = to_string(num);
    
            int maxVal = num, minVal = num;
    
            for(char ch = '0'; ch <= '9'; ch++){
                string t = s;
    
                for (char &c : t){
                    if(c == ch){
                        c = '0';
                    }
                }
    
    
                int val = stoi(t);
                minVal = min(minVal, val);
            }
    
    
    
            for(char ch = '0'; ch <= '9'; ch++){
                string t = s;
    
                for (char &c : t){
                    if(c == ch){
                        c = '9';
                    }
                }
    
    
                int val = stoi(t);
                maxVal = max(maxVal, val);
            }
    
    
            return maxVal - minVal;
        }
    };