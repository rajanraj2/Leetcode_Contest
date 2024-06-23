// Link - https://leetcode.com/problems/minimum-average-of-smallest-and-largest-elements/
// Minimum Average of Smallest and Largest Elements


class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        int n = nums.size();
        double min_avg = INT_MAX;
        vector<double> averages;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n/2; i++) {
            int mini = nums[i];
            int maxi = nums[n - i - 1];
            double avg = (double)mini + double(maxi - mini) / 2;
            min_avg = min(min_avg, avg);
        }
        min_avg = round(min_avg * 10) / 10.0;
        return min_avg; 
    }
};