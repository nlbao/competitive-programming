typedef long long ll;

class Solution
{
private:
    const int F = 0, W = 1, E = 2;
    const int winCases[3] = {E, F, W};
    const int loseCases[3] = {W, E, F};

    const ll MOD = 1e9 + 7;

    int f[2][2001][3];

    int charToInt(char ch)
    {
        if (ch == 'F')
            return F;
        if (ch == 'W')
            return W;
        return E;
    }

    inline int mmod(ll x)
    {
        return x % MOD;
    }

public:
    int countWinningSequences(string s)
    {
        int n = s.size();
        int a = charToInt(s[0]);
        f[0][1000][a] = 1;                // draw
        f[0][1000 + 1][loseCases[a]] = 1; // Bob wins
        f[0][1000 - 1][winCases[a]] = 1;  // Bob loses
        int i = 0;
        for (int pos = 1; pos < n; ++pos)
        {
            int a = charToInt(s[pos]);
            int bWin = loseCases[a];
            int bLose = winCases[a];
            int bDraw = a;
            int preI = i;
            i ^= 1;
            for (int c = 0; c <= 2000; ++c)
                for (int b = 0; b < 3; ++b)
                    f[i][c][b] = 0;
            for (int c = 0; c <= 2000; ++c)
            { // c = (Bob's points - Alice's points + 1000) at preI
                for (int preB = 0; preB < 3; ++preB)
                {
                    ll preF = f[preI][c][preB];
                    if (preF == 0)
                        continue;
                    // bob wins
                    if (preB != bWin)
                    {
                        f[i][c + 1][bWin] = mmod(f[i][c + 1][bWin] + preF);
                    }
                    // bob loses
                    if (preB != bLose)
                    {
                        if (c > 0)
                            f[i][c - 1][bLose] = mmod(f[i][c - 1][bLose] + preF);
                    }
                    // draw
                    if (preB != bDraw)
                    {
                        f[i][c][bDraw] = mmod(f[i][c][bDraw] + preF);
                    }
                }
            }
        }
        ll ans = 0;
        for (int c = 1001; c <= 2000; ++c)
            for (int lastB = 0; lastB < 3; ++lastB)
            {
                ans = mmod(ans + f[i][c][lastB]);
            }
        return ans;
    }
};