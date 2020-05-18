#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 3e5 + 5;
const ll BASE = 1e4 + 7;


int n;
char s[MAX_N];
ll p[MAX_N], h[MAX_N], g[MAX_N];
int cl[MAX_N], cr[MAX_N];


inline ll getH(int i, int j) {
	if (i < 1) return h[j];
	return h[j] - h[i-1] * p[j-i+1];
}


inline ll getG(int i, int j) {
	if (i >= n-1) return g[i];
	return g[i] - g[j+1] * p[j-i+1];
}


inline bool isPalindrome(int x, int y) {
	return getH(x, y) == getG(x, y);
}


inline void update_odd(int pos) {
	int l = 0, r = min(pos, n-1-pos), len = 0;
	while (l <= r) {
		int mid = (l+r)>>1;
		int x = pos-mid, y = pos+mid;
		if (isPalindrome(x, y)) {
			len = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	// cout << "	odd: " << pos << " " << len << endl;
	++cl[pos-len], --cl[pos+1];
	++cr[pos], --cr[pos+len+1];
}


inline void update_even(int pos) {
	if (s[pos] != s[pos+1]) return;
	int l = 0, r = min(pos, n-1-pos-1), len = 0;
	while (l <= r) {
		int mid = (l+r)>>1;
		int x = pos-mid, y = pos+1+mid;
		if (isPalindrome(x, y)) {
			len = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	// cout << "	even: " << pos << " " << len << endl;
	++cl[pos-len], --cl[pos+1];
	++cr[pos+1], --cr[pos+1+len+1];
}


int main() {
#ifdef DEBUG
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
#endif
	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		p[i] = p[i-1] * BASE;

	scanf("%s", s);
	n = strlen(s);
	h[0] = s[0];
	for (int i = 1; i < n; ++i)
		h[i] = h[i-1] * BASE + s[i];
	g[n-1] = s[n-1];
	for (int i = n-2; i >= 0; --i)
		g[i] = g[i+1] * BASE + s[i];

	filla(cl, 0);
	filla(cr, 0);
	for (int i = 0; i < n; ++i) {
		update_odd(i);
		if (i < n-1) update_even(i);
	}

	// for (int i = 0, s = 0; i < n; ++i) {
	// 	s += cl[i];
	// 	cout << s << " ";
	// }
	// cout << endl;
	// for (int i = 0, s = 0; i < n; ++i) {
	// 	s += cr[i];
	// 	cout << s << " ";
	// }
	// cout << endl;

	ll ans = 0, suml = 0, sumr = 0;
	for (int i = 0; i < n; ++i) {
		suml += cl[i];
		ans += sumr * suml;
		sumr += cr[i];
	}
	cout << ans;

	return 0;
}