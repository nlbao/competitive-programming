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
#include <complex>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef complex<double> base;


#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int PADDING = 5*int(1e4)+5;
const int MAX_N = 3*2*PADDING;
const double PI = acos(-1.0);


int n;
vector<ll> a, b, c;
int x[MAX_N], y[MAX_N], z[MAX_N];


void fft(vector<base> &a, bool invert) {
	int n = (int)a.size();
	for (int i = 1, j = 0; i < n; ++i) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1)
			j -= bit;
		j += bit;
		if (i < j)
			swap(a[i], a[j]);
	}

	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2*PI/len * (invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i < n; i += len) {
			base w(1);
			for (int j = 0; j < len/2; ++j) {
				base u = a[i+j], v = a[i+j+len/2] * w;
				a[i+j] = u + v;
				a[i+j+len/2] = u - v;
				w *= wlen;
			}
		}
	}

	if (invert)
		for (int i = 0; i < n; ++i)
			a[i] /= n;
}


void multiply(const vector<ll> &a, const vector<ll> &b, vector<ll> &res) {
	vector<base> fa(a.begin(), a.end());
	vector<base> fb(b.begin(), b.end());
	int n = 1, limit = max(a.size(), b.size());
	while (n < limit) n <<= 1;
	n <<= 1;
	fa.resize(n);
	fb.resize(n);

	fft(fa, false);
	fft(fb, false);
	for (int i = 0; i < n; ++i)
		fa[i] *= fb[i];
	fft(fa, true);

	res.resize(n);
	for (int i = 0; i < n; ++i)
		res[i] = ll(fa[i].real() + 0.5);
}


int main() {
#ifdef DEBUG
	freopen("POST2.in", "r", stdin);
	freopen("POST2.out", "w", stdout);
#endif
	filla(x, 0);
	filla(y, 0);
	filla(z, 0);

	n = read();
	for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &y[i]);
	for (int i = 0; i < n; ++i) scanf("%d", &z[i]);

	int minValue = *min_element(x, x+n);
	minValue = min(minValue, *min_element(y, y+n));
	for (int i = 0; i < n; ++i) {
		x[i] -= minValue;
		y[i] -= minValue;
		z[i] -= 2*minValue;
	}

	int maxValue = *max_element(x, x+n);
	maxValue = max(maxValue, *max_element(y, y+n));
	a.resize(maxValue+1, 0);
	b.resize(maxValue+1, 0);
	for (int i = 0; i < n; ++i) {
		++a[x[i]];
		++b[y[i]];
	}

	multiply(a, b, c);

	ll ans = 0;
	int limit = (int)c.size();
	for (int i = 0; i < n; ++i)
		if (z[i] < limit)
			ans += c[z[i]];
	printf("%lld\n", ans);

	return 0;
}