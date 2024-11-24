// https://leetcode.com/contest/weekly-contest-425/problems/rearrange-k-substrings-to-form-target-string/
// Rearrange k Substrings to Form Target String


class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        map<string, int> mpp1, mpp2;
        int n = s.size(), m = s.size();
        if (n % k != 0) return false;
        int len = n / k;
        int i = 0;
        while (i < n) {
            mpp1[(s.substr(i, len))]++;
            i += len;
        }
        i = 0;
        while (i < n) {
            mpp2[(t.substr(i, len))]++;
            i += len;
        }
        return mpp1 == mpp2;
        // if (mpp1.size() != mpp2.size()) return false;
        // int ms = mpp1.size();
        // for (auto it1 : mpp1 && auto it2 : mpp2) {
        //     if (it1 != it2) return false;
        //     cout << mpp1[i] << " " << mpp2[i] << endl;
        // }
        // return true;
    }
};