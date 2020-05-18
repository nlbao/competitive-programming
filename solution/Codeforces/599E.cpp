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


const int MAX_N = 15;
const int MAX_F = (1<<(MAX_N-2))+4;


int n, m, nQ, id[MAX_N];
bool isEdge[MAX_N][MAX_N], isParent[MAX_N][MAX_N], isNotParent[MAX_N][MAX_N];
bool ok1[MAX_F][MAX_N], ok2[MAX_F][MAX_N], ok3[MAX_F][MAX_N][MAX_N], ok4[MAX_F][MAX_F];
ll f[MAX_F][MAX_N];
vector<pii> lca[MAX_N];


inline bool check_0(int u, int v, int r) {
	if (u==v && r!=u) return 0;
	if ((u==1 || v==1) && r!=1) return 0;
	return 1;
}


void init(int nMask) {
	// filla(ok1, 0);
	filla(ok2, 0);
	filla(ok3, 0);
	filla(ok4, 0);
	// fori(x,0,nMask) fori(i,1,n) if (x&id[i]) {
	// 	ok1[x][i]=1;
	// 	fori(j,1,n) if (j!=i && (x&id[j]))
	// 		if (isParent[j][i] || isNotParent[i][j]) {
	// 			ok1[x][i]=0;
	// 			break;
	// 		}
	// }
	fori(x,0,nMask) fori(i,1,n) if (!(x&id[i])) {
		ok2[x][i]=1;
		fori(j,1,n) if (x&id[j])
			if (isParent[j][i] || isParent[i][j] || isEdge[j][i] || isEdge[i][j]) {
				ok2[x][i]=0;
				break;
			}
	}
	fori(x,0,nMask) fori(i,1,n) if (x&id[i]) fori(r,1,n) if (!(x&id[r])) {
		ok3[x][i][r]=1;
		fori(j,1,n) if (j!=i && (x&id[j]))
			if (isEdge[r][j]) {
				ok3[x][i][r]=0;
				break;
			}
	}
	fori(x,0,nMask) {
		fori(y,0,nMask) if (!(x&y)) {
			ok4[x][y]=1;
			fori(i,1,n) if (x&id[i]) {
				fori(j,1,n) if (y&id[j])
					if (isParent[i][j] || isParent[j][i] || isEdge[i][j] || isEdge[j][i]) {
						ok4[x][y]=0;
						break;
					}
				if (!ok4[x][y]) break;
			}
		}
	}
}


inline bool check1(int newMask, int newR) {
	fori(i,1,n) if (i!=newR && (newMask&id[i]))
		if (isParent[i][newR] || isNotParent[newR][i])
			return 0;
	return 1;
}


inline bool checkLCA(int mask, int r) {
	foreach(it, lca[r]) if ((mask&id[it->fr]) && (mask&id[it->sc])) return 0;
	return 1;
}


inline bool check(int mask, int r, int newMask, int newR) {
	int x=mask-newMask;
	// return ok1[newMask][newR] && ok2[x][newR] && ok3[newMask][newR][r] && ok4[newMask][x] && checkLCA(newMask, r);
	return check1(newMask, newR) && ok2[x][newR] && ok3[newMask][newR][r] && ok4[newMask][x] && checkLCA(newMask, r);
}


ll solve(int mask, int par) {
	if (mask==0) return 1;
	if (f[mask][par]>-1) return f[mask][par];

	ll ans=0;
	int x=0;
	do {
		if (x>0 && __builtin_clz(x)==__builtin_clz(mask))
			fori(r,1,n) if (x&id[r]) {
				if (!check(mask, par, x, r)) continue;
				ll t = solve(x-id[r], r) * solve(mask-x, par);
				ans += t;
			}
		x=(x+1+(~mask))&mask;
	} while (x);

	return f[mask][par]=ans;
}


int main() {
#ifdef DEBUG
	freopen("599E.in", "r", stdin);
	freopen("599E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(isEdge, 0);
	filla(isParent, 0);
	filla(isNotParent, 0);

	cin >> n >> m >> nQ;
	fori(i,1,n) id[i]=1<<(i-1);
	while (m--) {
		int u, v;
		cin >> u >> v;
		isEdge[u][v]=isEdge[v][u]=1;
	}
	while (nQ--) {
		int u, v, r;
		cin >> u >> v >> r;
		if (!check_0(u, v, r)) {
			cout << 0 << endl;
			return 0;
		}
		if (r!=u) isNotParent[u][v]=1;
		if (r!=v) isNotParent[v][u]=1;
		isParent[r][u]=isParent[r][v]=1;
		if (r!=u && r!=v) lca[r].pb(mp(u, v));
	}
	fori(i,1,n) isParent[i][i]=isNotParent[i][i]=0;

	filla(f, -1);
	int mask=0;
	fori(i,2,n) mask|=id[i];
	init(mask);
	cout << solve(mask, 1) << endl;

	return 0;
}