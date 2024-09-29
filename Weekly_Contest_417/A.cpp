// Link - https://leetcode.com/contest/weekly-contest-417/problems/find-the-k-th-character-in-string-game-i/description/
// Find the kth character in string game I


class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while (word.size() < k) {
            int s = word.size();
            for (int j = 0; j < s; j++) {
                if (word.size() > k) break;
                if (word[j] == 'z') word += "a";
                else word += char(word[j] + 1);
            }
        }
        return word[k - 1];
    }
};