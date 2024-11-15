/*
https://leetcode.com/problems/find-maximum-non-decreasing-array-length

Solution:
* Let s[i] = sum of elements of array[0..i].
* Let f[i] = the solution, i.e. max length possible, for the array[0..i].
* Let cost[i] = the smallest-sum possible group ends at i, to produce f[i].
* f[j] = 1 or max(f[i]+1), for every i < j that satisfy the cost[i] <= sum[i+1..j].
* <-> cost[i] <= sum[j] - sum[i]
* <-> cost[i] + sum[i] <= sum[j]    (1)
* So, for each j, we need to find an i that satisfy (1) and have maximum(f[j]).
* Observation 1: f[i] <= f[j] for every i <= j. Because we can just always append the elements [i..j] into the group of i.
* Observation 2: the smaller i, the bigger cost[j], because cost[j] = s[j]-s[i].
* --> Thus, the problem becomes: finding the LARGEST i that satisfy (1), which
can be solved by using a monotonic stack (non-descreasing), plus binary search. This is an O(Nlog(N)) solution.
*
* Observation 3: because sum[j] is non-decreasing, any i that works for j, is also works for k with k > j.
Thus, we don't need to do binary search, just maintain a pointer to i, and increasing it overtime.
This is an O(N) solution.
*/

typedef long long ll;

class Solution
{
public:
    int findMaximumLength(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> f(n, 0);
        vector<ll> s(n, 0);
        vector<ll> cost(n, 0);
        vector<int> q(n, -1); // non-decreasing queue
        s[0] = nums[0];
        f[0] = 1;
        cost[0] = nums[0];
        q[0] = 0;
        int queueSize = 1;
        int qIdx = 0;
        for (int j = 1; j < n; ++j)
        {
            // initalize variables at j
            s[j] = s[j - 1] + nums[j];
            cost[j] = s[j];
            f[j] = 1; // a group of all elements from 0 to j;
            // find the suitable i
            qIdx = min(qIdx, queueSize - 1);
            while (qIdx < queueSize - 1 && cost[q[qIdx + 1]] + s[q[qIdx + 1]] <= s[j])
            {
                ++qIdx;
            }
            int i = q[qIdx];
            if (cost[i] + s[i] <= s[j])
            {
                f[j] = f[i] + 1;
                cost[j] = s[j] - s[i];
            }
            // push j into the queue
            ll cmpValue = cost[j] + s[j];
            while (queueSize > 0 && cmpValue <= cost[q[queueSize - 1]] + s[q[queueSize - 1]])
            {
                --queueSize;
            }
            q[queueSize++] = j;
        }
        return f[n - 1];
    }
};