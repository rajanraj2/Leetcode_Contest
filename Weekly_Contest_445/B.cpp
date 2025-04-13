// https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
// 3517. Smallest Palindromic Rearrangement I


class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> arr(26);
        for (auto it : s) {
            arr[it - 'a']++;
        }
        string result = "";
        int n = s.size(), odd = -1;
        if (n <= 1) return s;
        for (int i = 0; i < 26; i++) {
            if (arr[i] % 2) {
                odd = i;
                arr[i]--;
            }
        }

        for (int i = 0; i < 26; i++) {
            if (arr[i] > 0) {
                string str(arr[i] / 2, ('a' + i));
                result += str;
                arr[i] /= 2;
            }
        }
        if (odd != -1) result += ('a' + odd);
        for (int i = 25; i >= 0; i--) {
            if (arr[i] > 0) {
                string str(arr[i], ('a' + i));
                result += str;
                arr[i] = 0;
            }
        }
        
        return result;
    }
};