class Solution {
    public:
        int maxCoins(vector<int>& a) {
            sort(a.begin(), a.end());
    
            int ans = 0;
            int s= 0, e = a.size() - 2;
    
    
            int n = a.size() / 3;
    
            while( n ){
                ans += a[e];
                e -= 2;
                n -= 1;
            }
    
            return ans;
    
    
    
    
        }
    };
    