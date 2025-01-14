class Solution {
public:
    int countSubstrings(string a, string b) {
        int ans = 0;


        unordered_map<string, int> mpp;

        for (int i = 0; i < a.size(); i++) {
            for (int j = i; j < a.size(); j++) {
                string c = a.substr(i, j - i + 1);
                int cLen = c.size();
                if(mpp.find(c) != mpp.end()){
                    ans += mpp[c];
                    continue;
                }
                int tot = 0;
                for (int k = 0; k <= b.size() - cLen; k++) {
                    string d = b.substr(k, cLen);
                    int count = 0;
                    for (int l = 0; l < d.size() && count != 2; l++) {
                        if (c[l] != d[l]) {
                            count += 1;
                        }
                    }

                    if (count == 1) {
                        tot += 1;
                    }
                }

                mpp[c] = tot;
                ans += tot;
            }
        }

        return ans;
    }
};