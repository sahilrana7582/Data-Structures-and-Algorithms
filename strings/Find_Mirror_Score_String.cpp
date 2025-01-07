#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
class Solution {
public:
    long long calculateScore(string s) {

        long long ans = 0;

        unordered_map<char, stack<int>> mpp;

        for(int i=0;i<s.size(); i++){
            char ch = char(219 - int(s[i]));
            if(mpp.find(ch) == mpp.end() || mpp[ch].empty()){
                mpp[s[i]].push(i);
            }else{
                ans += i - mpp[ch].top();
                mpp[ch].pop();
            }
        }

        return ans;
        
    }
};