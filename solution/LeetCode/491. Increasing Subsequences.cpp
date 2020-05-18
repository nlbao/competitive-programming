/*****************************************************************************
 * Author: nlbao
 * Problem: https://leetcode.com/contest/leetcode-weekly-contest-16a/problems/increasing-subsequences/
 *****************************************************************************/


class Solution {
public:
    int n;
    vector<int> tmp;
    vector<vector<int> > ans;


    void tryf(vector<int>& nums, int pos) {
        if (pos >= n) return;
        if (nums[pos] >= tmp.back()) {
            tmp.push_back(nums[pos]);
            ans.push_back(tmp);
            tryf(nums, pos+1);
            tmp.pop_back();
        }
        tryf(nums, pos+1);
    }


    vector<vector<int>> findSubsequences(vector<int>& nums) {
        ans.clear();
        n = nums.size();
        for (int i = 0; i < n-1; ++i) {
            tmp.clear();
            tmp.push_back(nums[i]);
            tryf(nums, i+1);
        }

        // remove duplications
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());

        return ans;
    }
};