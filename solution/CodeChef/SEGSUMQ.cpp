// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+5;
const int MAX_F = 5*MAX_N;


int L, R, n;
ll C, D;
pll a[MAX_N];
vector<int> id[MAX_F];
vector<ll> s1[MAX_F], s2[MAX_F];


inline bool isLessThan(const pll &a, const pll &b) {
	if (a.sc == 0 && b.sc == 0) return a.fr < b.fr;
	if (a.sc == 0) return false;
	if (b.sc == 0) return true;
	return a.fr*b.sc < a.sc*b.fr;
}


inline bool cmp(const int& i, const int& j) {
	return isLessThan(a[i], a[j]);
}


void init(int k, int l, int r) {
	int len=r-l+1;
	id[k].resize(len);
	for (int i = l; i <= r; ++i)
		id[k][i-l] = i;
	sort(id[k].begin(), id[k].end(), cmp);
	s1[k].resize(len);
	s2[k].resize(len);
	s1[k][0]=a[id[k][0]].fr;
	s2[k][0]=a[id[k][0]].sc;
	for (int i = l+1; i <= r; ++i) {
		int p = i-l;
		s1[k][p] = s1[k][p-1] + a[id[k][p]].fr;
		s2[k][p] = s2[k][p-1] + a[id[k][p]].sc;
	}
	if (l==r) return;
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	init(kl, l, mid);
	init(kr, mid+1, r);
}


int findPos(int k) {
	int l = 0, r = id[k].size()-1;
	if (D == 0) return l;
	if (C == 0) return r+1;
	int ans = r+1;
	pll p = mp(D, C);
	while (l<=r) {
		int mid=(l+r)>>1;
		if (isLessThan(p, a[id[k][mid]])) {
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	return ans;
}


ll solve(int k, int l, int r) {
	if (r < L || l > R) return 0;
	if (L <= l && r <= R) {
		ll ans = 0;
		int len = id[k].size();
		int pos = findPos(k);
		if (pos >= len) return 0;
		if (pos == 0) {
			ans -= D*(s2[k][len-1]);
			ans += C*(s1[k][len-1]);
		}
		else {
			ans -= D*(s2[k][len-1] - s2[k][pos-1]);
			ans += C*(s1[k][len-1] - s1[k][pos-1]);
		}
		return ans;
	}
	int mid=(l+r)>>1;
	int kl=k<<1, kr=kl+1;
	return solve(kl, l, mid) + solve(kr, mid+1, r);
}


int main() {
#ifdef DEBUG
	freopen("SEGSUMQ.in", "r", stdin);
	freopen("SEGSUMQ.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i].fr);
	for (int i = 1; i <= n; ++i) scanf("%lld", &a[i].sc);

	init(1, 1, n);

	int nQ;
	scanf("%d", &nQ);
	while (nQ--) {
		scanf("%d%d%lld%lld", &L, &R, &C, &D);
		printf("%lld\n", solve(1, 1, n));
		fflush(stdout);
	}

	return 0;
}