#include <cstdio>
#include <cstdlib>
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
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 1e5 + 5;
const int MAX_K = 2*(25*MAX_N+5);
const ll BASE = 1e4 + 7;


int n, u, v;
char s[MAX_N];
int key[MAX_K], cnt[MAX_K];
int sa[MAX_N], sb[MAX_N], rank[MAX_N];
bool mark[MAX_K];
ll p[MAX_N], h[MAX_N];
int f[4*MAX_N];


void build_sa() {
    s[n++] = 1;
    filla(cnt, 0);
    for (int i = 0; i < n; ++i) ++cnt[key[i] = s[i]];
    for (int i = 1; i < MAX_K; ++i) cnt[i] += cnt[i-1];
    for (int i = n-1; i >= 0; --i) sa[--cnt[key[i]]] = i;
    mark[0] = true;
    for (int i = 1; i < n; ++i) mark[i] = (key[sa[i-1]] != key[sa[i]]);

    for (int k = 1; k <= n; k <<= 1) {
        int nKey = 0;
        for (int i = 0; i < n; ++i) {
            if (mark[i]) ++nKey;
            key[sa[i]] = nKey;
            sb[i] = (sa[i] - k + n)%n;
        }
        filla(cnt, 0);
        for (int i = 0; i < n; ++i) ++cnt[key[i]];
        for (int i = 1; i <= nKey; ++i) cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; --i) sa[--cnt[key[sb[i]]]] = sb[i];
        for (int i = 1; i < n; ++i)
            mark[i] = mark[i] || (key[(sa[i-1]+k)%n] != key[(sa[i]+k)%n]);
    }
}


inline ll getH(int i, int j) {
	if (i > j) return 0;
	if (i == 0) return h[j];
	return h[j] - h[i-1] * p[j-i+1];
}


bool check(int id, int len, int pos) {
	// if (pos+len >= n) return false;
	if (pos+len >= n) return true;
	ll a = getH(id, id+len-1);
	ll b = getH(pos, pos+len-1);
	return a != b;
}


int find(int pos, int len) {
	int x = sa[pos];
	ll a = getH(x, x+len-1);
	int l = pos+1, r = n-1, ans = pos;
	while (l <= r) {
		int mid = (l+r)>>1;
		int y = sa[mid];
		if (y+len >= n) {
			r = mid-1;
			continue;
		}
		ll b = getH(y, y+len-1);
		if (a == b) {
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	return ans;
}


void buildIT(int k, int l, int r) {
	if (l > r) return;
	if (l == r) {
		f[k] = sa[l];
		return;
	}
	int mid = (l+r)>>1;
	int left = k<<1, right = left+1;
	buildIT(left, l, mid);
	buildIT(right, mid+1, r);
	f[k] = min(f[left], f[right]);
}


int get(int k, int l, int r) {
	if (l > r || l > v || r < u) return MAX_N;
	if (u <= l && r <= v) return f[k];
	int mid = (l+r)>>1;
	int left = k<<1, right = left+1;
	return min(get(left, l, mid), get(right, mid+1, r));
}


int getMinSa(int l, int r) {
	// int ans = sa[l];
	// for (int i = l+1; i <= r; ++i)
	// 	ans = min(ans, sa[i]);
	// return ans;
	u = l, v = r;
	return get(1, 1, n-1);
}


int test(int pos, int len) {
	int ans = sa[pos];
	ll a = getH(ans, ans+len-1);
	for (int i = pos+1; i < n; ++i) {
		int t = sa[i];
		if (t+len >= n) continue;
		ll b = getH(t, t+len-1);
		if (b == a) ans = min(ans, t);
	}
	return ans+1;
}


int solve(int id, int len) {
	int i = -1;
	int l = rank[--id]+1, r = n-1;
	while (l <= r) {
		int mid = (l+r)>>1;
		int t = sa[mid];
		if (check(id, len, t)) {
			i = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	if (i < 0) return -1;

	///////////////
	// while (i < n && sa[i]+len >= n) ++i;
	// if (i >= n) return -1;

	l = i, r = n-1;
	i = -1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (sa[mid]+len < n) {
			i = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	if (i < 0) return -1;

	// return test(i, len);
	///////////////

	int j = find(i, len);
	return getMinSa(i, j) + 1;
}


int main() {
#ifdef DEBUG
	freopen("ANKLEX.in", "r", stdin);
	freopen("ANKLEX.out", "w", stdout);
#endif
	scanf("%s", s);
	n = strlen(s);
	p[0] = 1;
	for (int i = 1; i < MAX_N; ++i)
		p[i] = p[i-1] * BASE;
	h[0] = s[0];
	for (int i = 1; i < n; ++i)
		h[i] = h[i-1]*BASE + ll(s[i]);

	build_sa();
	for (int i = 1; i < n; ++i)
		rank[sa[i]] = i;
	buildIT(1, 1, n-1);

	// for (int i = 0; i < n; ++i)
	// 	cout << sa[i] << " ";
	// cout << endl;

	int nQ = read();
	while (nQ--) {
		int id, len;
		scanf("%d%d", &id, &len);
		printf("%d\n", solve(id, len));
	}
	return 0;
}