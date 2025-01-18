class Solution {
public:
    int dp[101][201];
    const int MOD = 1e9 + 7;
    int solve(vector<int> &a, int s, int e, int &f){

        if(f < 0){
            return 0;
        }


        if(dp[s][f] != -1){
            return dp[s][f];
        }




        int ans = 0;

        if(s == e){
            ans += 1;
        }



        for(int i=0;i<a.size(); i++){
            if(i != s){
                int rem = f - abs(a[i]-a[s]);
                ans = (ans + solve(a, i, e, rem)) % MOD;
            }
        }


        return dp[s][f] = ans;
        
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp, -1, sizeof(dp));
        int ans = 0;
        return solve(locations, start, finish, fuel);
    }
};