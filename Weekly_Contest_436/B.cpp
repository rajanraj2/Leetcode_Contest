// https://leetcode.com/problems/assign-elements-to-groups-with-constraints/description/
// 3447. Assign Elements to Groups with Constraints


class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size(), s = elements.size();
        vector<int> result(n, -1);
        vector<pair<int, int>> arr;
        arr.reserve(s);
        
        for (int i = 0; i < s; i++) arr.push_back({elements[i], i});
        sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
            return a.second < b.second;
        });

        for (int i = 0; i < n; i++) {
            for (auto &it : arr) {
                if (groups[i] % it.first == 0) {
                    result[i] = it.second;
                    break;
                }
            }
        }
        
        return result;
    }
};