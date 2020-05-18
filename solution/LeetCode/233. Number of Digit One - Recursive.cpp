typedef long long ll;

class Solution {
public:
     int countDigitOne(int n) { 
        if (n < 1) return 0;
        if (n < 10) return 1;
        ll ans = 0, p10 = 1;
        while (p10*10 <= n) p10 *= 10;
        ll x = n/p10, r = n % p10;
        if (x == 1) {
            ans += countDigitOne(p10-1);        // total number of 1 in m, 0 <= m < p10 (in other words, len(m) < len(n)).
            ans += countDigitOne(r);            // total number of 1 of z in (1*p10 + z) with 0 <= z <= r.
            ans += r+1;                         // total number of FIRST 1 in (1*p10 + z) with 0 <= z <= r.
        }
        else {  // x > 1
            ans += x * countDigitOne(p10-1);    // total number of 1 in z in (k*p10 + z) with 0 <= k < x and 0 <= z < p10.
            ans += p10;                         // total number of FIRST 1 in (1*p10 + z) with 0 <= z < p10.
            ans += countDigitOne(r);            // total number of 1 in (x*p10 + t) with 0 <= t <= r.
        }
        return ans;
    }
};