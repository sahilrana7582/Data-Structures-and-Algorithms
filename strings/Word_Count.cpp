class Solution {
public:
    string largestWordCount(vector<string>& m, vector<string>& s) {

        map<string, int> mpp;

        for(int i = 0; i<m.size(); i++){
            string msg = m[i];
            string sender = s[i];
            int cnt = 0;

            for(char ch : msg){
                if(ch == ' '){
                    cnt += 1;
                }
            }
            cnt += 1;

            mpp[sender] += cnt;
        }

        string ans = "";
        int last = INT_MIN;

        for(auto pair : mpp){
            if(pair.second >= last){
                ans = pair.first;
                last = pair.second;
            }
        }

        return ans;
    }
};