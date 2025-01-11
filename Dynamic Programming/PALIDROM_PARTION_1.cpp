class Solution {
public:
    bool isPalidron(int st, int en, string &s){
        while(st < en){
            if(s[st] != s[en]){
                return false;
            }
            st++;
            en--;
        }
        return true;
    }
    void solve(int ind, string &s, vector<vector<string>> &ans, vector<string> temp){

        if(ind >= s.size()){
            ans.push_back(temp);
            return;
        }


        for(int i=ind;i<s.size();i++){
            if(isPalidron(ind, i, s)){
                temp.push_back(s.substr(ind, i - ind + 1));
                solve(i + 1, s, ans, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s, ans, temp);

        return ans;
        
    }
};