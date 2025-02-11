class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.find(part) < s.size()){
            int idx = s.find(part);
            s.erase(idx, part.size());
        }
        return s;
    }
};
