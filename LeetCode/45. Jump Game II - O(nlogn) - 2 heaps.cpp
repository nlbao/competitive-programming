/*****************************************************************************
 * Author: nlbao
 * Problem: https://leetcode.com/problems/jump-game-ii/
 *****************************************************************************/


typedef pair<int, int> pii;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int jump[n];
        jump[0] = 0;
        set<pii> destHeap;
        multiset<int> jumpHeap;
        destHeap.insert(pii(0+nums[0], 0));
        jumpHeap.insert(jump[0]);
        for (int i = 1; i < n; ++i) {
            jump[i] = n+1;
            while (!destHeap.empty() && destHeap.begin()->first < i) {
                int id = destHeap.begin()->second;
                jumpHeap.erase(jumpHeap.find(jump[id]));
                destHeap.erase(destHeap.begin());
            }
            if (jumpHeap.empty()) break;
            jump[i] = *jumpHeap.begin() + 1;
            jumpHeap.insert(jump[i]);
            destHeap.insert(pii(i+nums[i], i));
        }
        return jump[n-1];
    }
};