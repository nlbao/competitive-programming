typedef long long ll;
typedef pair<int, int> pii;

auto maxHeapCmp = [](pii a, pii b)
{ return a.first > b.first || (a.first == b.first && a.second > b.second); };

class Solution
{
private:
    set<pii> minHeap;
    set<pii, decltype(maxHeapCmp)> maxHeap;
    map<int, int> counts;
    ll sum = 0;

public:
    vector<long long> findXSum(vector<int> &nums, int k, int x)
    {
        int n = nums.size();
        for (int i = 0; i < k; ++i)
        {
            insertElement(nums[i]);
            balanceHeaps(x);
        }
        vector<ll> ans(1, sum);
        for (int i = k; i < n; ++i)
        {
            insertElement(nums[i]);
            removeElement(nums[i - k]);
            balanceHeaps(x);
            ans.push_back(sum);
        }
        return ans;
    }

    int getCount(int val)
    {
        int cnt = 0;
        auto it = counts.find(val);
        if (it == counts.end())
            counts[val] = 0;
        else
            cnt = it->second;
        return cnt;
    }

    void insertElement(int val)
    {
        int cnt = getCount(val);
        pii p = make_pair(cnt, val);
        removeFromBothHeaps({cnt, val});
        counts[val] = ++cnt;
        maxHeap.insert({cnt, val});
    }

    void removeElement(int val)
    {
        int cnt = getCount(val);
        removeFromBothHeaps({cnt, val});
        counts[val] = --cnt;
        if (cnt == 0)
            return;
        maxHeap.insert({cnt, val});
    }

    void removeFromBothHeaps(pii p)
    {
        auto it = minHeap.find(p);
        if (it != minHeap.end())
        {
            minHeap.erase(it);
            sum -= total(p);
            return;
        }
        it = maxHeap.find(p);
        if (it != maxHeap.end())
        {
            maxHeap.erase(it);
        }
    }

    void balanceHeaps(int x)
    {
        while (!maxHeap.empty() && (minHeap.size() < x || *maxHeap.begin() > *minHeap.begin()))
        {
            auto it = maxHeap.begin();
            sum += total(*it);
            minHeap.insert(*it);
            maxHeap.erase(it);
        }
        while (minHeap.size() > x)
        {
            auto it = minHeap.begin();
            sum -= total(*it);
            maxHeap.insert(*it);
            minHeap.erase(it);
        }
    }

    ll total(pii p)
    {
        return 1LL * p.first * p.second;
    }
};