typedef long long ll;

const ll MOD = 1e9 + 7;

inline ll mmod(ll x)
{
    return x % MOD;
}

int countBit1(int x)
{
    int ans = 0;
    while (x > 0)
    {
        ans += (x & 1);
        x >>= 1;
    }
    return ans;
}

const int EQUAL = 0;
const int SMALLER = 1;
const int BIGGER = 2;

class Solution
{
public:
    int countKReducibleNumbers(string s, int k)
    {
        int len = s.size();

        // cost[i] = number of required steps to reduce a binary string that has i bit "1".
        // cost[i] = cost[countBit1(i)] + 1
        vector<int> cost(len + 1, 0);
        cost[0] = cost[1] = 0;
        for (int i = 2; i <= len; ++i)
        {
            cost[i] = cost[countBit1(i)] + 1;
        }

        // f[i][m][ compareToS = {0, 1, 2} ] = number of binary strings that has currentLen, and has i bit "1",
        // and is equal, or already smaller, or already bigger than the prefix[0..currentLen] of s, depends on compareToS.
        // result = f[i][0..2]       when currentLen < len(s), and cost[i] <= k
        //        + f[i][SMALLER]    when currenLen == len(s), and cost[i] <= k
        vector<vector<vector<ll>>> f(2, vector<vector<ll>>(len + 1, vector<ll>(3, 0)));
        int turn = 0;
        if (s[0] == '0')
            f[turn][1][BIGGER] = 1; // "1" > "0..."
        else
            f[turn][1][EQUAL] = 1;                // "1" == "1..."
        ll ans = (len == 1) ? f[turn][1][SMALLER] // which == 0
                            : f[turn][1][0] + f[turn][1][1] + f[turn][1][2];

        for (int si = 1; si < len; ++si)
        {
            char ch = s[si];
            int currentLen = si + 1;
            int pre = turn;
            turn ^= 1;
            for (int i = 0; i <= currentLen; ++i)
                for (int c = 0; c < 3; ++c)
                    f[turn][i][c] = 0;
            for (int i = 1; i <= currentLen; ++i)
            {
                if (ch == '0')
                {
                    // if the i-th digit is 0:
                    f[turn][i][EQUAL] = f[pre][i][EQUAL];
                    f[turn][i][SMALLER] = f[pre][i][SMALLER];
                    f[turn][i][BIGGER] = f[pre][i][BIGGER];
                    // if the i-th digit is 1:
                    // f[turn][i][EQUAL] not change
                    f[turn][i][SMALLER] = mmod(f[turn][i][SMALLER] + f[pre][i - 1][SMALLER]);
                    f[turn][i][BIGGER] = mmod(f[turn][i][BIGGER] + f[pre][i - 1][EQUAL] + f[pre][i - 1][BIGGER]);
                }
                else
                { // ch == '1'
                    // if the i-th digit is 0:
                    // f[turn][i][EQUAL] not change
                    f[turn][i][SMALLER] = mmod(f[pre][i][EQUAL] + f[pre][i][SMALLER]);
                    f[turn][i][BIGGER] = f[pre][i][BIGGER];
                    // if the i-th digit is 1:
                    f[turn][i][EQUAL] = f[pre][i - 1][EQUAL];
                    f[turn][i][SMALLER] = mmod(f[turn][i][SMALLER] + f[pre][i - 1][SMALLER]);
                    f[turn][i][BIGGER] = mmod(f[turn][i][BIGGER] + f[pre][i - 1][BIGGER]);
                }
                // update ans
                if (cost[i] + 1 > k)
                    continue;
                if (currentLen < len)
                {
                    for (int c = 0; c < 3; ++c)
                    {
                        ans = mmod(ans + f[turn][i][c]);
                    }
                }
                else
                {
                    ans = mmod(ans + f[turn][i][SMALLER]);
                }
            }
        }
        return ans;
    }
};