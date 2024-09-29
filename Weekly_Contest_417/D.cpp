// Link - https://leetcode.com/contest/weekly-contest-417/problems/find-the-k-th-character-in-string-game-ii/
// Find the kth character in string game II


class Solution {
public:
    string op0(string word) {
        word = word + word;
        return word;
    }

    string op1(string word, long long k) {
        int s = word.size();
        for (int j = 0; j < s; j++) {
            if (word.size() > k) return word;
            if (word[j] == 'z') word += "a";
            else word += char(word[j] + 1);
        }
        return word;
    }

    char kthCharacter(long long k, vector<int>& operations) {
        string word = "a";

        while (word.size() < k) {
            for (int it : operations) {
                if (it == 0) {
                    word = op0(word);
                }
                else if (it == 1) {
                    word = op1(word, k);
                }
            }
        }

        return word[k - 1];
    }
};