
class Solution {
    public:
        int balancedStringSplit(string s) {
    
            int n = s.size();
    
            int i = 0, l = 0, r = 0, ans = 0;
    
            while(i < n){
                char ch = s[i];
                if(ch == 'L'){
                    l += 1;
                }else {
                    r += 1;
                }
    
    
                if(l == r){
                    ans += 1;
                    l = 0;
                    r = 0;
                }
    
                i += 1;
            }
    
    
            return ans;
            
        }
    };