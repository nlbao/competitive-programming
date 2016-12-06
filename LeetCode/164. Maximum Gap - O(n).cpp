typedef long long ll;

class Solution {
public:
    static const ll oo = 2*ll(INT_MAX);

    int maximumGap(vector<int>& a) {
        int n = a.size();
        if (n < 2) return 0;

        int maxA = *max_element(a.begin(), a.end());
        int minA = *min_element(a.begin(), a.end());
        if (maxA == minA) return 0;

        double blockSize = 1.0 * (maxA-minA) / (n-1);
        vector<ll> maxVal(n, 1LL*(-oo));
        vector<ll> minVal(n, 1LL*oo);
        for (int i = 0; i < n; ++i) {
            int index = (a[i] - minA) / blockSize;
            maxVal[index] = max(maxVal[index], 1LL*a[i]);
            minVal[index] = min(minVal[index], 1LL*a[i]);
        }

        ll ans = 0, pre = -oo;
        for (int i = 0; i < n; ++i) {
            if (minVal[i] == oo) continue;
            if (pre > -oo)
                ans = max(ans, minVal[i] - pre);
            pre = maxVal[i];
        }
        return ans;
    }
};