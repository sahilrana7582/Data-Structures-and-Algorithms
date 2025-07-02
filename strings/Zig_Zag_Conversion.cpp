#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= s.size())
            return s;

        vector<string> res;             
        vector<string> ans(numRows);     
        int idx = 0, n = s.size();

        while (idx < n) {
            string temp(numRows, '#');
            for (int i = 0; i < numRows && idx < n; i++) {
                temp[i] = s[idx++];
            }
            res.push_back(temp);

            for (int i = 0; i < numRows - 2 && idx < n; i++) {
                string diag(numRows, '#');
                int indToPutOnChar = numRows - i - 2;  
                diag[indToPutOnChar] = s[idx++];
                res.push_back(diag);
            }
        }

        for (const string& str : res) {
            for (int i = 0; i < numRows; i++) {
                char ch = str[i];
                if (ch != '#' && ch != '\0') {
                    ans[i].push_back(ch);
                }
            }
        }

        string result;
        for (const string& row : ans) {
            result += row;
        }

        return result;
    }
};
