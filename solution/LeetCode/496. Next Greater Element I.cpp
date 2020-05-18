class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> ans;
        int n = findNums.size(), m = nums.size();
        for (int i = 0; i < n; ++i) {
            int x = -1;
            bool found = false;
            for (int k = 0; k < m; ++k)
                if (nums[k] == findNums[i]) found = true;
                else if (nums[k] > findNums[i]) {
                    if (found) {
                        x = nums[k];
                        break;
                    }
                }
            ans.push_back(x);
        }
        return ans;
    }
};