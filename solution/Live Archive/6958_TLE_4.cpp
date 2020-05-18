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


const int MAX_N = 15;
const int MAX_F = 1<<MAX_N;


int n, nMask;
ll L, w[MAX_N][MAX_N];
set<ll> a[MAX_F][MAX_N];
bool ok[MAX_F];


inline bool find() {
	int y;
	ll t;
	fori(x,1,nMask) if (ok[x]) fori(i,2,n) {
		y=nMask-x;
		y|=1;
		y|=1<<(i-1);
		if (!ok[y]) continue;
		foreach(it, a[x][i]) {
			t=L-*it;
			if (t<0) break;
			if (a[y][i].find(t) != a[y][i].end())
				return 1;
		}
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("6958.in", "r", stdin);
	// freopen("test.in", "r", stdin);
	freopen("6958.out", "w", stdout);
#endif
	while (scanf("%d%lld", &n, &L) != EOF) {
		fori(i,1,n) fori(j,1,n) scanf("%lld", &w[i][j]);
		nMask=(1<<n)-1;
		fori(x,0,nMask) {
			fori(i,1,n) a[x][i].clear();
			int c=__builtin_popcount(x);
			ok[x]=(c<=7) && (x&1);
		}
		fori(i,1,n) a[1<<(i-1)][i].insert(0);
		fori(x,0,nMask) fori(i,1,n) if (ok[x] && !a[x][i].empty()) {
			fori(j,2,n) {
				int y=x|(1<<(j-1));
				if (y==x || !ok[y]) continue;
				foreach(it, a[x][i]) {
					ll val=*it+w[i][j];
					if (val>L) break;
					a[y][j].insert(val);
				}
			}
		}
		if (find()) printf("possible\n");
		else printf("impossible\n");
	}

	return 0;
}