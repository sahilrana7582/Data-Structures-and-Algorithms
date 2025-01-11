class Solution {
public:
    int longestSubarray(vector<int>& a) {

        if(a.size() == 1){
            return 0;
        }
        int ans = 0;
        int z = 0;

        int l = 0, r = 0;

        while(r < a.size()){
            if(a[r] == 1){
            }else{
                if( z < 1){
                    z++;
                }else{
                    while(a[l] == 1){
                        l++;
                    }
                    l++;
                }
            }
            int win = (r - l) + 1;
            ans = max(ans, win);
            r++;
        }


        return ans == 0 ? 0 :  ans - 1;
    }
};