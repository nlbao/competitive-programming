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


const int MAX_LEN = int(1e4)+4;
const double PI = acos(-1.0);


char sa[MAX_LEN], sb[MAX_LEN];
vector<ll> a, b, c;
vector<int> ans;


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
	freopen("MUL.in", "r", stdin);
	freopen("MUL.out", "w", stdout);
#endif
	int nTest = readln();
	while (nTest--) {
		scanf("%s %s\n", sa, sb);

		int na = strlen(sa), nb = strlen(sb);
		a.resize(na, 0);
		b.resize(nb, 0);
		for (int i = 0; i < na; ++i)
			a[i] = sa[na-1-i] - '0';
		for (int i = 0; i < nb; ++i)
			b[i] = sb[nb-1-i] - '0';

		multiply(a, b, c);

		ll carry = 0;
		ans.clear();
		int n = (int)c.size();
		for (int i = 0; i < n; ++i) {
			carry += c[i];
			ans.push_back(carry%10);
			carry /= 10;
		}
		while (carry > 0) {
			ans.push_back(carry%10);
			carry /= 10;
		}

		int len = (int)ans.size();
		if (len == 0) ++len;
		while (len > 1 && ans[len-1] == 0) --len;
		for (int i = len-1; i >= 0; --i)
			printf("%d", ans[i]);
		printf("\n");
	}
	return 0;
}