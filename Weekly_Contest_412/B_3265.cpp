// Link - https://leetcode.com/problems/count-almost-equal-pairs-i/
// Count Almost Equal Pairs I


class Solution {
private:
    bool helper(int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);
        int i1 = -1, i2 = -1;
        if (sa.size() != sb.size()) {
            while (sa.size() < sb.size()) sa = "0" + sa;
            while (sb.size() < sa.size()) sb = "0" + sb;
            
        }

        
        for (int i = 0; i < sa.size(); i++) {
            if (sa[i] != sb[i]){
                if (i1 == -1) {
                    i1 = i;
                } 
                else if (i2 == -1) {
                    i2 = i;
                }
                else {
                    return false;
                }
            }
        }

        if (i1 == -1) return true;
        if (i2 == -1) return false;
        
        swap(sa[i1], sa[i2]);

        return sa == sb;
    }


public:
    int countPairs(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (helper(nums[i], nums[j])) {
                    count++;
                }
            }
        }
        return count;
    }
};