// Link - https://leetcode.com/problems/count-the-number-of-good-nodes/
// Count the Number of Good Nodes


class Solution {
public:
    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> result(n);

        for (auto& edge : edges) {
            result[edge[0]].push_back(edge[1]);
            result[edge[1]].push_back(edge[0]);
        }

        vector<int> sizes(n, 0);
        
        function<int(int, int)> calculate = [&](int node, int parent) {
            int size = 1;
            for (int child : result[node]) {
                if (child != parent) {
                    size += calculate(child, node);
                }
            }
            sizes[node] = size;
            return size;
        };

        calculate(0, -1);

        int goodNodeCount = 0;

        function<void(int, int)> isGood = [&](int node, int parent) {
            unordered_set<int> sizeset;
            for (int child : result[node]) {
                if (child != parent) {
                    sizeset.insert(sizes[child]);
                }
            }

            if (sizeset.size() <= 1) {
                goodNodeCount++;
            }

            for (int child : result[node]) {
                if (child != parent) {
                    isGood(child, node);
                }
            }
        };

        isGood(0, -1);

        return goodNodeCount;
    }
};