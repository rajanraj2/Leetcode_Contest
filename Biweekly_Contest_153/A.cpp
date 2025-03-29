// https://leetcode.com/problems/reverse-degree-of-a-string/
// 3498. Reverse Degree of a String


class Solution {
public:
    int reverseDegree(string s) {
        int result = 0, count = 1;
        for (auto it : s) {
            int val = it - 'a';
            val = 26 - val;
            result += val * count;
            count++;
        }
        return result;
    }
};