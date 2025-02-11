class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_map<string, int> mpp; 
        string ans;
        
        for(char ch : word){
            if(isdigit(ch)){
                ans += ch;
            } else {
                if (!ans.empty()) { 
                    while (ans.size() > 1 && ans[0] == '0') {
                        ans.erase(0, 1); 
                    }
                    mpp[ans]++; 
                    ans = "";
                }
            }
        }

        if (!ans.empty()) { 
            while (ans.size() > 1 && ans[0] == '0') {
                ans.erase(0, 1);
            }
            mpp[ans]++;
        }

        return mpp.size();
    }
};
