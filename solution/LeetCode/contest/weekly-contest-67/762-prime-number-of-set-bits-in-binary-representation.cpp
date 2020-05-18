typedef long long ll;

#define sqr(x) ((x)*(x))

class Solution {
public:
    static const int MAX_P = 40;
    static const int MAX_R = 1e6+1;

    Solution() {
        // memset(_is_prime, true, sizeof(_is_prime));
        for (int i = 0; i < MAX_P; ++i)
            _is_prime[i] = true;
        _is_prime[0] = _is_prime[1] = false;
        for (int i = 2; i < MAX_P; ++i) {
            if (!_is_prime[i]) continue;
            for (ll k = sqr(ll(i)); k < MAX_P; k += i)
                _is_prime[k] = false;
        }
        // cal sumCnt
        _sumCnt[0] = 0;
        for (int i = 1; i < MAX_R; ++i) {
            int nBit = __builtin_popcount(i);
            _sumCnt[i] = _sumCnt[i-1] + int(_is_prime[nBit]);
        }
    }

    int countPrimeSetBits(int L, int R) {
        return _sumCnt[R] - _sumCnt[L-1];
    }

private:
    bool _is_prime[MAX_P];
    int _sumCnt[MAX_R];
};