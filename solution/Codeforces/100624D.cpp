#pragma comment(linker, "/STACK:1024000000")
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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


const int MAX_N = 2e5+5;
const int oo = 1e9+7;


int n;
int pos[MAX_N], pl[MAX_N], pr[MAX_N], a[MAX_N];
map<int, int> id;


bool solve(int l, int r) {
	if (l>=r) return 1;
	if (l+1==r) return a[l]!=a[l+1];
	for (int i=l, j=r; i<=j; ++i, --j) {
		if (pl[i]<l && r<pr[i]) return solve(l, i-1) && solve(i+1, r);
		if (pl[j]<l && r<pr[j]) return solve(l, j-1) && solve(j+1, r);
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("100624D.in", "r", stdin);
	freopen("100624D.out", "w", stdout);
#endif
	int nTest;
	scanf("%d", &nTest);
	while (nTest--) {
		scanf("%d", &n);
		id.clear();
		fori(i,1,n) {
			scanf("%d", &a[i]);
			id[a[i]];
		}
		int m=0;
		foreach(it, id) it->sc=++m;
		fori(i,1,n) a[i]=id[a[i]];

		fori(i,1,m) pos[i]=-oo;
		fori(i,1,n) pl[i]=pos[a[i]], pos[a[i]]=i;
		fori(i,1,m) pos[i]=oo;
		ford(i,n,1) pr[i]=pos[a[i]], pos[a[i]]=i;

		if (solve(1,n)) printf("non-boring\n");
		else printf("boring\n");
	}

	return 0;
}