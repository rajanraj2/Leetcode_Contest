// https://leetcode.com/problems/find-minimum-cost-to-remove-array-elements/
// 3469. Find Minimum Cost to Remove Array Elements


class Solution {
    public:
        int minCost(vector<int>& nums) {
            int n = nums.size(), result = 0;
            unordered_map<int, int> mpp;
            for (int i = 0; i < n; i++) {
                mpp[nums[i]]++;
            }
    
            while (nums.size() > 2) {
                int count = 0, maxi2 = 0;
                int maxi = max({nums[0], nums[1], nums[2]});
                if (maxi == nums[0]) count++;
                else maxi2 = nums[0];
                if (maxi == nums[1]) count++;
                else maxi2 = max(maxi2, nums[1]);
                if (maxi == nums[2]) count++;
                else maxi2 = max(maxi2, nums[2]);
    
                if (count == 3) {
                    nums.erase(nums.begin(), nums.begin() + 2);
                    mpp[maxi] -= 2;
                    result += maxi;
                    continue;
                }
    
                if (count == 2) {
                    int sz0 = nums.size();
                    int ind = 1;
                    if (nums[0] == maxi) nums.erase(find(nums.begin(), nums.end(), maxi));
                    if (sz0 != nums.size()) ind = 0;
                    if (nums[ind] == maxi) nums.erase(find(nums.begin(), nums.end(), maxi));
                    if (sz0 - nums.size() != 2 && nums[1] == maxi) {
                        nums.erase(find(nums.begin(), nums.end(), maxi));
                    }
                    mpp[maxi] -= 2;
                    result += maxi;
                    continue;
                }
    
                // if (mpp[maxi] > 1) {
                    int sz0 = nums.size();
                    int ans = 0;
                    if (nums[0] != maxi) {
                        
                        nums.erase(find(nums.begin(), nums.end(), nums[0]));
                        mpp[nums[0]]--;
                    }
                    int ind = 1;
                    if (nums.size() != sz0) ind = 0;
                    if (nums[ind] != maxi) {
                        nums.erase(find(nums.begin(), nums.end(), nums[1]));
                        mpp[nums[1]]--;
                    }
                    if (sz0 - nums.size() == 1 && nums[1] != maxi) {
                        nums.erase(find(nums.begin(), nums.end(), nums[2]));
                        mpp[nums[2]]--;
                    }
                    result += maxi2;
                    cout << result << endl;
                cout << nums.size() << "dsf\n";
                
                    continue;
                // }
    
                result += maxi;
                nums.erase(find(nums.begin(), nums.end(), maxi));
                nums.erase(find(nums.begin(), nums.end(), maxi2));
                mpp[maxi]--;
                mpp[maxi2]--;
            }
            
            
            if (nums.size() > 0) {
                result += *max_element(nums.begin(), nums.end());
                cout << nums[0];
            }
            return result;
        }
    };