typedef long long ll;

class Solution
{
private:
    const int MAX_NUM = 5 * 10000 + 1;

public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int n = nums.size();
        vector<int> divisibleCount = vector<int>(MAX_NUM, 0);
        for (int i = 0; i < n; ++i)
        {
            int x = nums[i];
            for (int y = 1; y <= x; ++y)
            {
                int z = x / y;
                if (y > z)
                    break;
                if (x % y != 0)
                    continue;
                ++divisibleCount[y];
                if (y == z)
                    break; // y == sqrt(x)
                ++divisibleCount[z];
            }
        }

        // f[x] = number of pairs that have gcd() == x
        // f[x] = (divisibleCount[x] * (divisibleCount[x]-1) / 2) - sum( f[k*x] )
        vector<ll> f = vector<ll>(MAX_NUM, 0);
        for (int x = MAX_NUM - 1; x > 0; --x)
        {
            f[x] = 1LL * divisibleCount[x] * (divisibleCount[x] - 1) / 2;
            if (f[x] == 0)
                continue;
            for (int k = 2; k < MAX_NUM; ++k)
            {
                int t = k * x;
                if (t >= MAX_NUM)
                    break;
                f[x] -= f[t];
            }
            assert(f[x] >= 0);
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