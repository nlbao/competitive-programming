/*
len(n) = Ln
len(x) = Lx
if Lx < Ln:
    call this f(Lx):
        choose k positions in Lx to be 1
        (Lx-k) remain positions can be anything from 0-9 (except position 0)
        if x[0] == 1:
            number of ways = c[k-1][Lx-1] * 9^(Lx-k)
        else:
            number of ways = 8 * c[k][Lx-1] * 9^(Lx-1-k)
        ==> ans = k * (c[k-1][Lx-1] * 9^(Lx-k) + 8 * c[k][Lx-1] * 9^(Lx-1-k))
if Lx == Ln:
    suppose we have the prefix: x[0..i-1] == n[0..i-1]
                    and x[i] < n[i]
    ==> x[i+1..Lx-1] can be anything (because x already < n)
    let number of 1's in x[0..i] be cntPrefix1
    ==> ans = cntPrefix1 * 10^(Lx-i-1) + g(Lx-i-1)
    with g(k) = f(1) + f(2) + ... + f(k)
*/


typedef long long ll;

class Solution {
public:
    Solution() {
        p10[0] = p9[0] = 1;
        for (int i = 1; i < MAX_N; ++i) {
            p10[i] = p10[i-1] * 10;
            p9[i] = p9[i-1] * 9;
        }
        memset(c, 0, sizeof(c));
        for (int i = 0; i < MAX_N; ++i) {
            c[i][0] = c[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                c[i][j] = c[i-1][j] + c[i-1][j-1];
            }
        }

        ansWithLen[0] = ansNotLongerThan[0] = 0;
        for (int i = 1; i < MAX_N; ++i) {
            ansWithLen[i] = f(i);
            ansNotLongerThan[i] = ansNotLongerThan[i-1] + ansWithLen[i];
        }
    }

    ll f(int len) {
        if (len < 1) return 0;
        if (len == 1) return 1;
        ll ans = 0;
        for (int k = 1; k <= len; ++k) {
            ll numberOfWays = getC(k-1, len-1) * p9[len-k];        // x[0] == 1
            numberOfWays += 8LL * getC(k, len-1) * p9[len-1-k];    // 2 <= x[0] <= 9
            ans += numberOfWays * k;
        }
        return ans;
    }

    ll g(int len) {
        ll ans = 0;
        for (int i = 1; i <= len; ++i)
            ans += f(i);
        return ans;
    }

    int countDigitOne(int n) {
        if (n < 1) return 0;

        // converts n to a string
        string s = "";
        while (n > 0) {
            s = to_string(n%10) + s;
            n /= 10;
        }
        if (s == "") s = "0";

        // Lx < Ln
        int Ln = s.size();
        ll ans = ansNotLongerThan[Ln-1];

        // Lx == Ln
        ll cntPrefix1 = 0;
        for (int i = 0; i < Ln; ++i) {
            int limit = s[i]-'0';
            for (int x = (i == 0) ? 1 : 0; x < limit; ++x) {
                ll cnt1 = cntPrefix1 + ll(x == 1);
                ans += cnt1 * p10[Ln-i-1] + ansNotLongerThan[Ln-i-1];
            }
            cntPrefix1 += (limit == 1);
        }
        ans += cntPrefix1;  // n itself

        return ans;
    }

private:
    static const int MAX_N = 11;
    ll p10[MAX_N], p9[MAX_N];
    ll c[MAX_N][MAX_N];
    ll ansWithLen[MAX_N], ansNotLongerThan[MAX_N];

    ll getC(int k, int n) {
        if (k < 0 || k > n) return 0;
        return c[n][k];
    }
};