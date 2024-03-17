// https://leetcode.com/problems/minimum-moves-to-pick-k-ones/description/
// https://leetcode.com/contest/weekly-contest-389

typedef long long ll;

class Solution
{
public:
    long long minimumMoves(vector<int> &nums, int k, int maxChanges)
    {
        int n = nums.size();
        vector<int> pos;
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] == 1)
                pos.push_back(i);
        }

        int nPos = pos.size();
        assert(maxChanges + nPos >= k);
        if (nPos == 0)
        {
            return 2 * k;
        }

        int l = 0, r = 1; // r-l = available pickups
        ll ans = 1e10;
        ll swapCost = 0;
        for (int i = 0; i < nPos; ++i)
        {
            // try dylanIndex=i
            int x = pos[i];
            bool hasLeft = (x > 0 && nums[x - 1] == 1);
            bool hasRight = (x < n - 1 && nums[x + 1] == 1);
            int changes = max(min(maxChanges, k - 1 - hasLeft - hasRight), 0);
            int requiredSwaps = k - changes;
            ll changeCost = 2 * changes;

            if (i > 0)
            {
                ll dist = ll(x - pos[i - 1]);
                swapCost += dist * (i - l); // total distance to all the left pos
                swapCost -= dist * (r - i); // total distance to all the right pos
            }

            while (r <= i)
            {
                swapCost += x - pos[r];
                ++r;
            }
            if (requiredSwaps > r - l && l > 0)
            {
                // try 1 step backward
                --l;
                swapCost += x - pos[l];
            }
            while (requiredSwaps > r - l && r <= nPos - 1)
            {
                // try 1 step forward
                swapCost += pos[r] - x;
                ++r;
            }
            if (requiredSwaps > r - l)
                continue;

            // remove redundant l
            while (r - l > requiredSwaps && l < i)
            {
                swapCost -= (x - pos[l]);
                ++l;
            }

            // now try to optimize swapCost
            while (r <= nPos - 1 && l < i)
            {
                ll newSwapCost = swapCost - (x - pos[l]) + (pos[r] - x);
                if (newSwapCost >= swapCost)
                    break;
                swapCost = newSwapCost;
                ++l;
                ++r;
            }
            ans = min(ans, changeCost + swapCost);
        }
        return ans;
    }
};