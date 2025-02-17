class Solution {
public:
    string intToRoman(int num) {
        map<int, string, greater<int>> mpp = {
            {1, "I"},   {4, "IV"},   {5, "V"},   {9, "IX"},  {10, "X"},
            {40, "XL"}, {50, "L"},   {90, "XC"}, {100, "C"}, {400, "CD"},
            {500, "D"}, {900, "CM"}, {1000, "M"}};

        string a = to_string(num);
        int n = a.size() - 1;

        string ans;

        for(auto &pair : mpp){
            while( num >= pair.first ){
                num -= pair.first;
                ans += pair.second;
            }
        }

        return ans;
    }
};