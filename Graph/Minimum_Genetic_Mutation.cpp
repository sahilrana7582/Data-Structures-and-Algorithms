class Solution {
public:
    int minMutation(string s, string e, vector<string>& b) {
        unordered_set<string> st(
            b.begin(), b.end());
        if (st.find(e) == st.end())
            return -1;

        queue<pair<string, int>> q; 
        unordered_set<string> vis;

        vector<char> chars = {'A', 'C', 'G', 'T'};

        q.push({s, 0});

        while(!q.empty()){
            string temp = q.front().first;
            int cnt = q.front().second;
            q.pop();

            if(temp == e){
                return cnt;
            }

            for(int i=0; i<8; i++){
                char originalChar = temp[i];

                for(char ch : chars){
                    temp[i] = ch;

                    if(st.find(temp) != st.end() && vis.find(temp) == vis.end()){
                        q.push({temp, cnt + 1});
                        vis.insert(temp);
                    }


                    temp[i] = originalChar;

                }
            }

        }


        return -1;
    }
};