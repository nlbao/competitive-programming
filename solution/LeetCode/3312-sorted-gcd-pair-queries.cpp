typedef long long ll;

class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int n = nums.size();
        int MAX_NUM = *max_element(nums.begin(), nums.end()) + 1;
        vector<int> freq = vector<int>(MAX_NUM, 0);
        for (int i = 0; i < n; ++i)
        {
            ++freq[nums[i]];
        }

        // f[x] = number of pairs that have gcd() == x
        // f[x] = (divisibleCount(x) * (divisibleCount(x)-1) / 2) - sum( f[k*x] )
        // where divisibleCount(x) = sum( freq[x] + freq[2*x] + ... )
        vector<ll> f = vector<ll>(MAX_NUM, 0);
        for (int x = MAX_NUM - 1; x > 0; --x)
        {
            ll divisibleCount = freq[x];
            for (int t = 2 * x; t < MAX_NUM; t += x)
            {
                divisibleCount += freq[t];
                f[x] -= f[t];
            }
            f[x] += divisibleCount * (divisibleCount - 1) / 2;
        }

        // s[x] = f[1] + f[2] + ... + f[x]
        vector<ll> s = vector<ll>(MAX_NUM, 0);
        for (int x = 1; x < MAX_NUM; ++x)
        {
            s[x] = s[x - 1] + f[x];
        }

        // for queries[i], do binary search to find the smallest pos that satisfy s[pos] >= queries[i]+1
        int m = queries.size();
        vector<int> ans = vector<int>(m, -1);
        for (int i = 0; i < m; ++i)
        {
            ll q = queries[i] + 1;
            int l = 0, r = MAX_NUM - 1, pos = -1;
            while (l <= r)
            {
                int mid = (l + r) >> 1;
                if (s[mid] >= q)
                {
                    pos = mid;
                    r = mid - 1;
                }
                else
                    l = mid + 1;
            }
            ans[i] = pos;
        }
        return ans;
    }
};