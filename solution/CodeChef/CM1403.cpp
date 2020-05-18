#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

#define maxd 200
#define digit 9
#define base 1000000000

string toString(int i) {
	string s = "";
	while (i > 0) {
		s.push_back(char(i+'0'));
		i /= 10;
	}
	if (s.length() == 0) s = "0";
	return s;
}

struct bignum {
    inline static bignum tobignum (string a) {
        bignum c;
        c.reset();
        for(int i = 0; i < (int)a.length(); i++)
            c = c*10 + (a[i]-'0');
        return c;
    }
    inline static bignum tobignum (ll n) {
        bignum c;
        c.reset();
        return c+n;
    }
    ll a[maxd];
    inline void reset() { memset(a, 0, sizeof a); }
    inline ll &operator [](int i) { return a[i]; }
    inline friend bignum operator * (bignum a, bignum b) {
        bignum c;
        c.reset();
        for(int i = maxd-1; i >= 1; i--) {
            ll cr = 0;
            for(int j = maxd-1; j >= 1; j--) {
                if (i+j > maxd-1) {
                    int k = i+j-(maxd-1);
                    c[k] = c[k] + a[i]*b[j] + cr;
                    cr = c[k] / base;
                    c[k] = c[k] % base;
                }
            }
        }
        return c;
    }
    inline friend bignum operator * (bignum a,  ll b) {
        bignum c;
        ll cr = 0;
        for(int i = maxd-1; i >= 1; i--) {
            c[i] = (a[i]*b + cr) % base;
            cr = (a[i]*b + cr) / base;
        }
        return c;
    }
    inline friend bignum operator + (bignum a,  ll b) {
        bignum c;
        for(int i = maxd-1; i >= 1; i--) {
            c[i] = (a[i]+b) % base;
            b = (a[i]+b) / base;
        }
        return c;
    }
    inline friend bignum operator + (bignum a,  bignum b) {
        bignum c;
        ll cr = 0;
        for(int i = maxd-1; i >= 1; i--) {
            c[i] = (a[i] + b[i] + cr) % base;
            cr = (a[i] + b[i] + cr) / base;
        }
        return c;
    }

    inline friend bignum operator - (bignum a,  bignum b) {
        bignum c;
        ll cr = 0;
        for(int i = maxd-1; i >= 1; i--) {
            c[i] = a[i]-b[i]-cr;
            if (c[i] < 0) {
                c[i] += base;
                cr = 1;
            }
            else cr = 0;
        }
        return c;
    }
    inline friend bignum operator - (bignum a,  ll b) {
        bignum b1;
        b1.reset();
        b1 = b1+b;
        return a-b1;
    }
    inline void print() {
    	// string ans = "", t;
    	// for (int i = 0; i < maxd; ++i) {
    	// 	t = toString(a[i]);
    	// 	while (t.length() < digit)
    	// 		t = "0"+t;
    	// 	ans = t+ans;
    	// }
    	// cout << ans << endl;

        for(int i = 1; i < maxd; i++)
            if (a[i] > 0) {
                printf("%lld", a[i]);
                for(int j = i+1; j < maxd; j++)
                    printf("%09lld", a[j]);
                    // printf("%lld", a[j]);
                printf("\n");
                return;
            }
        printf("0\n");
    }
    inline friend bool operator < (bignum a, bignum b) {
        for(int i = 1; i < maxd; i++)
            if (a[i] < b[i]) return 1;
            else if (a[i] > b[i]) return 0;
        return 0;
    }
};
inline static bignum tobignum (string a) {
    bignum c;
    c.reset();
    for(int i = 0; i < (int)a.length(); i++)
        c = c*10 + (a[i]-'0');
    return c;
}
inline static bignum tobignum (ll n) {
    bignum c;
    c.reset();
    return c+n;
}


const int MAX_N = 5055;

int nHouse, nTownship, crrTurn, maxD;
int a[MAX_N], turn[MAX_N];
bignum f[MAX_N], g[MAX_N], value;


void update(int i) {
	if (i > a[nHouse-1]) return;
	if (turn[i] != crrTurn) {
		f[i] = tobignum("0");
		turn[i] = crrTurn;
	}
	if (i == 0) {
		f[i] = value;
		return;
	}
	f[i] = f[i] + value;
	update(i + (i & (-i)));
}


bignum get(int i) {
	if (i < 0) return tobignum("0");
	if (turn[i] != crrTurn) {
		f[i] = tobignum("0");
		turn[i] = crrTurn;
	}
	if (i == 0) return f[0];
	return f[i] + get(i - (i & (-i)));
}


int main() {
#ifdef DEBUG
	// freopen("CM1403.in", "r", stdin);
	freopen("test.in", "r", stdin);
	freopen("CM1403.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		nHouse = read();
		maxD = read();
		for (int i = 0; i < nHouse; ++i)
			a[i] = read();
		nTownship = read();

		crrTurn = 0;
		filla(turn, 0);
		f[a[0]] = tobignum("1");
		for (int id = 0; id < nTownship; ++id) {
			int l = read(), r = read();
			for (int i = l; i <= r; ++i) {
				int x = a[i];
				g[i] = get(x-1);
				if (x-maxD-1 > 0)
					g[i] = g[i] - get(x-maxD-1);
				// printf("i = %d, x = %d, g = ", i, x);
				// g[i].print();
				// printf("\n");
			}
			++crrTurn;
			for (int i = l; i <= r; ++i) {
				value = g[i];
				update(a[i]);
			}
		}

		int x = a[nHouse-1];
		value = get(x-1);
		if (x-maxD-1 > 0)
			value = value - get(x-maxD-1);
		value.print();
		printf("\n");
	}
	return 0;
}