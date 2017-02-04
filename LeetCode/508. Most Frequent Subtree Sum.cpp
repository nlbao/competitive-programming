/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    map<int, int> sumCount;


    int dfs(TreeNode* root) {
        if (!root) return 0;
        int sum = root->val;
        sum += dfs(root->left) + dfs(root->right);
        ++sumCount[sum];
        return sum;
    }


    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        sumCount.clear();
        dfs(root);
        int maxCount = 0;
        for (auto it: sumCount)
            maxCount = max(maxCount, it.second);
        for (auto it: sumCount)
            if (it.second == maxCount)
                ans.push_back(it.first);
        return ans;
    }
};