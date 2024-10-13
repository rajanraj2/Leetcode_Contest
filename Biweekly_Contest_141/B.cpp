// Link - https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
// Construct the Minimum Bitwise OR Array II


class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 2) continue;
            int place = -1;
            string b = bitset<32>(nums[i]).to_string();
            for (int j = 0; j < b.size(); j++) {
                if (b[j] == '1') {
                    place = j;
                    break;
                }
            }
            if (place != -1) b.erase(0, place);

            int index = -1;
            for (int j = b.size() - 1; j >= 0; j--) {
                if (b[j] == '0') {
                    index = j;
                    break;
                }
            }
            
            if (index == -1) result[i] = nums[i] / 2;
            else {
                if (index + 1 < b.size()) {
                    b[index + 1] = '0';
                }
                for (int i = index + 2; i < b.size(); i++) {
                    b[i] = '1';
                }
                result[i] = stoi(b, nullptr, 2);
            }
        }
        return result;
    }
};