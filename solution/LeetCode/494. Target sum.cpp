/*****************************************************************************
 * Author: nlbao
 * Problem: https://leetcode.com/contest/leetcode-weekly-contest-16a/problems/target-sum/
 *****************************************************************************/


typedef long long ll;

#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)


class Solution {
public:
    void generateSum(vector<int>& nums, int l, int r, map<int, int>& s) {
        s.clear();
        int n = r-l+1;
        int nMask = 1<<n;
        for (int mask = 0; mask < nMask; ++mask) {
            ll sum = 0;
            for (int i = 0; i < n; ++i)
                if (mask & (1<<i))
                    sum += nums[l+i];
                else
                    sum -= nums[l+i];
            if (s.find(sum) == s.end()) s[sum] = 1;
            else s[sum] += 1;
        }
    }


    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        if (n < 1) return 0;
        if (n == 1) return int(nums[0] == target) + int(-nums[0] == target);

        int n1 = n/2, n2 = n-n1;
        map<int, int> s1, s2;
        generateSum(nums, 0, n1-1, s1);
        generateSum(nums, n1, n-1, s2);

        int ans = 0;
        foreach(it, s2) {
            ll val2 = it->first;
            int cnt2 = it->second;
            ll val1 = target - val2;
            if (s1.find(val1) != s1.end()) {
                // cout << val1 << " " << val2 << ": " << s1[val1] << " " << cnt2 << endl;
                ans += s1[val1] * cnt2;
            }
        }

        return ans;
    }
};


