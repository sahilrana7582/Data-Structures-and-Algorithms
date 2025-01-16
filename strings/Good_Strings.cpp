class Solution {
public:
    int numSplits(string s) {

        unordered_map<char, int> freq;
        for(char ch:s){
            freq[ch]++;
        }

        int ans = 0;

        unordered_set<char> st;

        for(char ch : s){


            if(st.find(ch) == st.end()){
                st.insert(ch);
            }


            freq[ch]--;


            if(freq[ch] == 0){
                freq.erase(ch);
            }

            if(st.size() == freq.size()){
                ans+=1;
            }
        }
        return ans;
        
    }
};