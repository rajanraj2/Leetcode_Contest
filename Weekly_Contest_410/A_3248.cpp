// Link - https://leetcode.com/problems/snake-in-matrix/
// Snake in Matrix


class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int pos = 0;
        for (auto it : commands) {
            if (it == "RIGHT") {
                pos++;
            }
            else if (it == "LEFT") {
                pos--;
            }
            else if (it == "DOWN") {
                pos += n;
            }
            else if (it == "UP") {
                pos -= n;
            }
        }
        return pos;
    }
};