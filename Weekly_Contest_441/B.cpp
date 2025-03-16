// https://leetcode.com/problems/closest-equal-element-queries/description/
// 3488. Closest Equal Element Queries


class Solution {
    public:
        vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
            int n = nums.size(), q = queries.size();
            vector<int> result(q, -1);
            map<int , vector<int>> mpp;
            for (int i = 0; i < n; i++) {
                mpp[nums[i]].push_back(i);
            }
    
            for (int i = 0; i < q; i++) {
                int val = nums[queries[i]];
                int sz = mpp[val].size();
                if (sz <= 1) continue;
    
                auto &vec = mpp[val];
                auto it = lower_bound(vec.begin(), vec.end(), queries[i]);
                if(it == vec.end() || *it != queries[i]) continue;
                
                int j = it - vec.begin();
                int index = vec[j];
                int prev, next;
                if (j == 0) prev = vec.back();
                else prev = vec[j - 1];
                if (j == sz - 1) next = vec.front();
                else next = vec[j + 1];
    
                int d1 = abs(index - prev);
                int d2 = abs(index - next);
                int circ_d1 = min(d1, n - d1);
                int circ_d2 = min(d2, n - d2);
                result[i] = min(circ_d1, circ_d2);
                
            }
            return result;
        }
    };