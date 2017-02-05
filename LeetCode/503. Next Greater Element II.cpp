class Solution {
public:
    int sz;
    vector<int> stk;


    void insert(int val) {
        while (sz > 0 && stk[sz-1] <= val) {
            stk.pop_back();
            --sz;
        }
        stk.push_back(val);
        ++sz;
    }


    int find(int val) {
        int l = 0, r = sz-1, ans = -1;
        while (l <= r) {
            int mid = (l+r)>>1;
            if (stk[mid] <= val) r = mid-1;
            else {
                ans = stk[mid];
                l = mid+1;
            }
        }
        return ans;
    }


    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        sz = 0;
        stk.clear();
        for (int i = n-1; i >= 0; --i)
            insert(nums[i]);
        for (int i = n-1; i >= 0; --i) {
            ans[i] = find(nums[i]);
            insert(nums[i]);
        }

        return ans;
    }
};