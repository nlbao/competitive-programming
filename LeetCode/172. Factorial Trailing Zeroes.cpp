typedef long long ll;

class Solution {
public:
    int trailingZeroes(int n) {
        if (n < 1) return 0;
        int ans = 0;
        for (ll i = 5; i <= n; i *= 5)
            ans += n / i;
        return ans;
    }
};