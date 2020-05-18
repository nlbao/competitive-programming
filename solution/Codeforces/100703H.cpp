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


const int MAX_N = 1e5 + 5;


int n, nQ, u, v;
pii a[MAX_N], q[MAX_N];
int sum[MAX_N], ans[MAX_N];


int cal(int k) {
	int ans = 0;
	for (int i = u, pos = 0; i < v; ++i) {
		int x = a[i].second;
		if (pos <= x) {
			++ans;
			pos = x + k+1;
		}
	}
	return ans;
}


inline void inc(int l, int r, int value) {
	if (l > r) return;
	sum[l] += value;
	sum[r+1] -= value;
}


void solve(int l, int r) {
	if (l > r) return;
	if (l == r) {
		inc(l, l, cal(q[l].first));
		return;
	}
	int fl = cal(q[l].first), fr = cal(q[r].first);
	inc(l, l, fl);
	inc(r, r, fr);
	if (l+1 >= r) return;

	int mid = (l+r)>>1;
	int fmid = cal(q[mid].first);
	inc(mid, mid, fmid);

	if (fmid == fl) inc(l+1, mid-1, fmid);
	else solve(l+1, mid-1);

	if (fmid == fr) inc(mid+1, r-1, fmid);
	else solve(mid+1, r-1);
}


int main() {
#ifdef DEBUG
	freopen("100703H.in", "r", stdin);
	freopen("100703H.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		a[i] = pii(read(), i+1);
	sort(a, a+n);

	scanf("%d", &nQ);
	for (int i = 0; i < nQ; ++i)
		q[i] = pii(read(), i);
	sort(q, q+nQ);

	filla(sum, 0);
	for (int i = 0, j = 0; i < n; i = j) {
		while (j < n && a[j].first == a[i].first) ++j;
		u = i, v = j;
		solve(0, nQ-1);
	}

	for (int i = 0, c = 0; i < nQ; ++i) {
		c += sum[i];
		ans[q[i].second] = c;
	}
	for (int i = 0; i < nQ; ++i)
		printf("%d ", ans[i]);
	return 0;
}