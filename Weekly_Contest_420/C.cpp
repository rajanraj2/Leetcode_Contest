// Link - https://leetcode.com/contest/weekly-contest-420/problems/minimum-division-operations-to-make-array-non-decreasing/description/
// Minimum Division Operations to Make Array Non-Decreasing


class Solution {
public:
    int divisor(int x){
        int maxi = 1;
        for(int i = 2; i<=sqrt(x); i++){
            if(x%i == 0){
                maxi = max(maxi,i);
                if(x/i!=i){
                    maxi = max(maxi,x/i);
                }
            }
        }
        return maxi;
    }

    int minOperations(vector<int>& nums) {
        int result = 0;
        for (int i = nums.size() - 1; i > 0; i--) {

            while (nums[i - 1] >= nums[i]) {

                int prev = nums[i - 1];
                int div = divisor(nums[i - 1]);
                if (div != -1) nums[i - 1] = nums[i - 1] / div;
                if (prev == nums[i - 1]) break;
                result++; 
            }
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return -1;
        }
        return result;
    }
};