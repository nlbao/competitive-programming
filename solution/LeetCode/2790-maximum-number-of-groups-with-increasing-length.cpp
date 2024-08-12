/*
    https://leetcode.com/problems/maximum-number-of-groups-with-increasing-length
*/

class Solution
{

public:
    int maxIncreasingGroups(vector<int> &usageLimits)
    {
        sort(usageLimits.begin(), usageLimits.end());
        // observation: the result can never exceed N=usageLimits.size(), because of the distinction condition.
        int result = 0, l = 0, r = usageLimits.size();
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (canCreateGroups(mid, usageLimits))
            {
                result = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return result;
    }

private:
    // usageLimits must be sorted ascendingly.
    bool canCreateGroups(int nGroup, const vector<int> &usageLimits)
    {
        int n = usageLimits.size();
        priority_queue<int> maxHeap(usageLimits.begin(), usageLimits.begin() + n - nGroup);
        priority_queue<int, vector<int>, greater<int>> minHeapCandidates(usageLimits.begin() + n - nGroup, usageLimits.end());

        int used = 0; // how many are used.
        for (int start = 0; start < nGroup; ++start)
        {
            while (minHeapCandidates.top() - used <= 0)
            {
                if (maxHeap.empty())
                    return false; // no replacement found.
                int newCandidate = maxHeap.top();
                maxHeap.pop();
                minHeapCandidates.pop();
                minHeapCandidates.push(newCandidate + used); // because we will aplly -used in later calculations.
            }

            ++used; // use one item from each candidate.
            if (start == nGroup - 1)
                break;

            // At the end, remove the minimum candidate, and put it into the heap.
            // Because the next group only needs one candidate fewer than this group.
            int minimumCandidateNewValue = minHeapCandidates.top() - used;
            minHeapCandidates.pop();
            if (minimumCandidateNewValue > 0)
            {
                maxHeap.push(minimumCandidateNewValue);
            }
        }
        return true;
    }
};
g