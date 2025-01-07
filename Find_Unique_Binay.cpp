class Solution {
public:
    void solve(int ind, string &ans, int n, string temp, unordered_map<string, bool> &mpp){
        if(temp.size() == n){
            if(!mpp[temp]){
                ans = temp;
            }
            return;
        }



        for(int i=0;i<=1;i++){
            temp += to_string(i);
            solve(ind + 1, ans, n, temp, mpp);
            temp.pop_back();
            if(!ans.empty()){
                return;
            }
        }
    }
    string findDifferentBinaryString(vector<string>& nums) {

        unordered_map<string, bool> mpp;
        int n;
        for(string s:nums){
            mpp[s] = true;
            n = s.size();
        }


        string ans;


        solve(0, ans, n, "", mpp);
        return ans;


        
    }
};