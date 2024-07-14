// Link - https://leetcode.com/contest/weekly-contest-406/problems/minimum-cost-for-cutting-cake-ii/
// Minimum Cost for Cutting Cake II


class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        sort(horizontalCut.rbegin(), horizontalCut.rend());
        sort(verticalCut.rbegin(), verticalCut.rend());

        int h = 0, v = 0;
        int hCount = 1, vCount = 1;
        long long totalCost = 0;

        while (h < horizontalCut.size() && v < verticalCut.size()) {
            if (horizontalCut[h] >= verticalCut[v]) {
                totalCost += horizontalCut[h] * vCount;
                hCount++;
                h++;
            } else {
                totalCost += verticalCut[v] * hCount;
                vCount++;
                v++;
            }
        }

        while (h < horizontalCut.size()) {
            totalCost += horizontalCut[h] * vCount;
            h++;
        }
        while (v < verticalCut.size()) {
            totalCost += verticalCut[v] * hCount;
            v++;
        }

        return totalCost;
    }
};