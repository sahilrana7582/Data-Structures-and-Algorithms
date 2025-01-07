class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int m = 1; 
        int ans = 0;

        while (n > 8) {
            ans += m * 8; 
            n -= 8;       
            m++;           
        }

        if (n > 0) {
            ans += m * n;
        }

        return ans;
    }
};
