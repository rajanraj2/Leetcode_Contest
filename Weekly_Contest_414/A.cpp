// Link - https://leetcode.com/contest/weekly-contest-414/problems/convert-date-to-binary/
// Convert Date to Binary


class Solution {
private:
    string toBinary(int n) {
        string ans = "";
        while (n) {
            if (n % 2 == 0) ans += "0";
            else ans += "1";
            n /= 2;
        }
        reverse(ans.begin(), ans.end());

        int i;
        for (i = 0; i < ans.size(); i++) {
            if (ans[i] != '0') break;
        }
        ans.erase(0, i);

        return ans;
    }

public:
    string convertDateToBinary(string date) {
        int i = 0;
        string result = "";
        while (i < date.size()) {
            int val = 0;
            while (date[i] != '-' && i < date.size()) {
                int num = date[i] - '0';
                if (val == 0) val += num;
                else val = val * 10 + num;
                i++;
            }

            string binary = toBinary(val);
            result += binary + "-";

            i++;
        }
        result.pop_back();
        return result;
    }
};