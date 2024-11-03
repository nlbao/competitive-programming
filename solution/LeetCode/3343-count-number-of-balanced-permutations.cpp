/**

https://leetcode.com/problems/count-number-of-balanced-permutations/description/

You are given a string num. A string of digits is called balanced if the sum of
the digits at even indices is equal to the sum of the digits at odd indices.

Return the number of distinct permutations of num that are balanced.
Since the answer may be very large, return it modulo 109 + 7.

A permutation is a rearrangement of all the characters of a string.

*/

typedef long long ll;

class Solution
{
private:
    const ll MOD = 1e9 + 7;

    inline ll mmod(ll x)
    {
        return x % MOD;
    }

public:
    int countBalancedPermutations(string num)
    {
        int n = num.size(), sum = 0;
        int freq[10];
        for (int i = 0; i < 10; ++i)
            freq[i] = 0;
        for (int i = 0; i < n; ++i)
        {
            int x = num[i] - '0';
            ++freq[x];
            sum += x;
        }
        if (sum & 1)
            return 0; // odd sum

        // prepare c[n][k] = number of ways to choose k elements from n elements
        vector<vector<ll>> c(n + 1, vector<ll>(n + 1, 0));
        c[0][0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            c[i][0] = c[i][i] = 1;
            for (int k = 1; k < i; ++k)
            {
                c[i][k] = mmod(c[i - 1][k - 1] + c[i - 1][k]);
            }
        }
        //////

        int halfSum = sum / 2;
        int nOdd = (n + 1) / 2; // number of odd indicies
        // f[turn][i][k] = number of distinct permutations that have i elements at odd indicies, and their sum is k,
        // and there are (COUNT-i) elements at even indicies, and their sum is (sumCOUNT - k),
        // with COUNT is the current total number of elements, and sumCOUNT is the corresponding total sum.
        vector<vector<vector<ll>>> f(2, vector<vector<ll>>(nOdd + 1, vector<ll>(halfSum + 1, 0)));
        int turn = 0, totalFreq = 0;
        f[turn][0][0] = 1;
        for (int x = 0; x < 10; ++x)
        {
            int freqX = freq[x];
            int pre = turn;
            turn = turn ^ 1;
            for (int i = 0; i <= nOdd; ++i)
                for (int k = 0; k <= halfSum; ++k)
                    f[turn][i][k] = 0;
            for (int i = 0; i <= nOdd; ++i)
            {
                int nEven = totalFreq - i;
                for (int k = 0; k <= halfSum; ++k)
                {
                    ll preF = f[pre][i][k];
                    if (preF == 0)
                        continue;
                    // ii = number of digit x that goes to odd indicies, kk = their sum.
                    int limitII = min(freqX, nOdd - i);
                    int limitKK = halfSum - k;
                    for (int ii = 0, kk = 0; ii <= limitII && kk <= limitKK; ++ii, kk += x)
                    {
                        int xEven = freqX - ii;
                        // count = (number of ways to "merge" ii digit x into the current i-digits string)
                        //       * (number of ways to "merge" xEven digit x into the current nEven-digits string)
                        ll count = mmod(c[i + ii][ii] * c[nEven + xEven][xEven]);
                        f[turn][i + ii][k + kk] = mmod(f[turn][i + ii][k + kk] + mmod(preF * count));
                    }
                }
            }
            totalFreq += freqX;
        }
        return f[turn][nOdd][halfSum];
    }
};