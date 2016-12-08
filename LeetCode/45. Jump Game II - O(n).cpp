/*****************************************************************************
 * Author: nlbao
 * Problem: https://leetcode.com/problems/jump-game-ii/
 *****************************************************************************/


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;
        int lastReach = 0, canReach = 0, step = 0;
        for (int i = 0; i < n && lastReach < n-1; ++i) {
            if (canReach < i) break;
            canReach = max(canReach, i+nums[i]);
            if (i == lastReach) {
                ++step;
                lastReach = canReach;
            }
        }
        return step;
    }
};
