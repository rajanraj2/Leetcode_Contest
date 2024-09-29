// Link - https://leetcode.com/contest/weekly-contest-417/problems/count-of-substrings-containing-every-vowel-and-k-consonants-i/description/
// Count of substrings containing every vowel and k consonants I


class Solution {
public:
    pair<int, int> vowel(string s) {
        int check = 0, c = 0, a = 0, e = 0, i = 0, o = 0, u = 0;
        for (char it : s) {
            if (it == 'a') a++;
            else if (it == 'e') e++;
            else if (it == 'i') i++;
            else if (it == 'o') o++;
            else if (it == 'u') u++;
            else c++;
        }
        if (a > 0 && e > 0 && i > 0 && o > 0 && u > 0) check = 1;
        return {check, c};
    }

    int countOfSubstrings(string word, int k) {
        int n = word.size(), result = 0;
        for (int i = 0; i <= n - k - 5; i++) {
            int j = 5 + k;
            while (true) {
                if (i + j > n) break;
                string s = word.substr(i, j);
                pair<int, int> p = vowel(s);
                if (p.first == 1 && p.second == k) result++; 
                j++;
            }
        }
        return result;
    }
};