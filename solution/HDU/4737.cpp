#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+5;


int n, M;
ll a[MAX_N], f[MAX_N], g[MAX_N];


ll solve(int l, int r) {
	if (l>r) return 0;
	if (l==r) return a[l]<M;
	int mid=(l+r)>>1;
	ll ans = solve(l,mid) + solve(mid+1,r);
	g[mid]=a[mid];
	ford(i,mid-1,l) g[i]=g[i+1] | a[i];
	f[mid+1]=a[mid+1];
	fori(i,mid+2,r) f[i]=f[i-1] | a[i];
	for (int i=mid, j=r; i>=l; --i) {
		while (j>mid && (g[i]|f[j]) >= M) --j;
		if (j<=mid) break;
		ans += (j-mid);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("4737.in", "r", stdin);
	freopen("4737.out", "w", stdout);
#endif
	// ios_base::sync_with_stdio(0);	cin.tie(0);
	// cout.precision(9);
	// cout.setf(ios::fixed, ios::floatfield);

	int nTest;
	scanf("%d", &nTest);
	fori(testid,1,nTest) {
		scanf("%d%d", &n, &M);
		fori(i,1,n) {
			int x;
			scanf("%d", &x);
			a[i]=x;
		}
		printf("Case #%d: %lld\n", testid, solve(1, n));
	}

	return 0;
}