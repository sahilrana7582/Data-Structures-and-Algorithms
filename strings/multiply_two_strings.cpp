class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0)
                sum += (num1[i--] - '0');
            if (j >= 0)
                sum += (num2[j--] - '0');

            carry = sum / 10;
            result += (sum % 10 + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }

    string solve(string& a, string& b) {
        int n = a.size(), m = b.size();
        string result = "0"; 

        for (int i = n - 1; i >= 0; i--) {
            int carry = 0;
            string tempAns = "";

            tempAns.append(n - 1 - i, '0');

            for (int j = m - 1; j >= 0; j--) {
                int nInt = a[i] - '0';
                int mInt = b[j] - '0';

                int tot = (nInt * mInt) + carry;
                carry = tot / 10;
                tempAns += to_string(tot % 10);
            }

            if (carry > 0) {
                tempAns += to_string(carry);
            }

            reverse(tempAns.begin(), tempAns.end()); 
            result = addStrings(result, tempAns);
        }

        while (result.size() > 1 && result[0] == '0') {
            result.erase(result.begin());
        }

        return result;
    }
    string multiply(string num1, string num2) {
        int n = num1.size();
        int m = num2.size();

        if (num1 == "0" || num2 == "0") {
            return "0";
        }


        return solve(num1, num2);

    }
};