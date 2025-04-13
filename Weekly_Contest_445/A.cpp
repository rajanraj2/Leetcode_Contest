// https://leetcode.com/problems/find-closest-person/
// 3516. Find Closest Person


class Solution {
public:
    int findClosest(int x, int y, int z) {
        int a = abs(z - x);
        int b = abs(z - y);
        if (a == b) return 0;
        else if (a < b) return 1;
        else return 2;
    }
};