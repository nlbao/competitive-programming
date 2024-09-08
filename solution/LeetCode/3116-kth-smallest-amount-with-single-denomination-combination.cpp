/*
    https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination
*/
typedef long long ll;

class Solution
{
public:
    long long findKthSmallest(vector<int> &coins, int k)
    {
        // setup
        sort(coins.begin(), coins.end());
        int n = coins.size(), maskLimit = 1 << n;
        lcmOfMask[0] = 1;
        numberBitOneOfMask[0] = 0;
        for (int mask = 1; mask < maskLimit; ++mask)
        {
            numberBitOneOfMask[mask] = 0;
            lcmOfMask[mask] = 1;
            bool calculated = false;
            for (int i = 0; i < n; ++i)
                if (mask & (1 << i))
                {
                    ++numberBitOneOfMask[mask];
                    if (!calculated)
                    {
                        lcmOfMask[mask] = lcm(lcmOfMask[mask ^ (1 << i)], coins[i]);
                        calculated = true;
                    }
                }
        }

        // find
        ll l = coins[0], r = ll(k) * coins[0], ans = -1;
        while (l <= r)
        {
            ll mid = (l + r) >> 1;
            ll nDistinct = countDistinction(coins, mid);
            if (nDistinct >= k)
            {
                if (nDistinct == k && isDivisible(mid, coins))
                    ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }

private:
    static const int MAX_N = 15;
    static const int MAX_MASK = 1 << MAX_N;
    ll lcmOfMask[MAX_MASK];
    int numberBitOneOfMask[MAX_MASK];

    ll countDistinction(const vector<int> &coins, ll limit)
    {
        ll count = limit / coins[0];
        for (int i = 1, n = coins.size(); i < n; ++i)
        {
            int maskLimit = 1 << i; // covers combinations of coins[0..i-1]
            for (int mask = 0; mask < maskLimit; ++mask)
            {
                // inclusive-exclusive
                ll maskLcm = lcmOfMask[mask | (1 << i)];
                if (numberBitOneOfMask[mask] & 1)
                    count -= (limit / maskLcm);
                else
                    count += (limit / maskLcm);
            }
        }
        return count;
    }

    bool isDivisible(ll value, const vector<int> &coins)
    {
        for (int i = 0, n = coins.size(); i < n; ++i)
            if (value % coins[i] == 0)
                return true;
        return false;
    }

    ll lcm(ll a, ll b)
    {
        return a * b / gcd(a, b);
    }

    ll gcd(ll a, ll b)
    {
        if (a < b)
            swap(a, b);
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};