typedef pair<int, int> pii;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans(n, "");
        vector<pii> a;
        for (int i = 0; i < n; ++i)
            a.push_back(pii(-nums[i], i));
        sort(a.begin(), a.end());
        if (n > 0) ans[a[0].second] = "Gold Medal";
        if (n > 1) ans[a[1].second] = "Silver Medal";
        if (n > 2) ans[a[2].second] = "Bronze Medal";
        for (int i = 3; i < n; ++i)
            ans[a[i].second] = to_string(i+1);
        return ans;
    }
};