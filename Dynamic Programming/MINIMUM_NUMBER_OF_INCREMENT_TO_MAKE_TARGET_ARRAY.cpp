class Solution {
public:
    int minNumberOperations(vector<int>& t) {
        int n = t.size() - 1;

        int last = 0;
        int ans = 0;
        for(int i=n;i>=0;i--){
            if(last < t[i]){
                ans += abs(last - t[i]);
            }
            last = t[i];
        }


        return ans;

        
    }
};