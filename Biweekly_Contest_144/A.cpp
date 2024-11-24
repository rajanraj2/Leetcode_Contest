// https://leetcode.com/problems/stone-removal-game/
// Stone Removal Game


class Solution {
public:
    bool canAliceWin(int n) {
        bool result = false;
        int stone = 10;
        // if (n < 10) return result;
        while (n > 0 && stone > 0) {
            if (stone > n) return result;
            n -= stone--;
            result = !result;
        }
        return result;
    }
};