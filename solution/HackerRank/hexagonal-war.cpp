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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1505;
const int MAX_C = sqr(MAX_N);
const int dx[6] = {-1, -1, 0, 0, +1, +1};
const int dy[6] = {0, +1, -1, +1, 0, -1};


int n, nC, nQ;
int id[MAX_N][MAX_N], p1[MAX_C], p2[MAX_C], color[MAX_C];
vector<int> e[MAX_C];


int getRoot(int u, int p[]) {
	return p[u]<1 ? u : p[u]=getRoot(p[u], p);
}


int main() {
#ifdef DEBUG
	freopen("hexagonal-war.in", "r", stdin);
	freopen("hexagonal-war.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> nQ;
	filla(id, 0);
	nC=0;
	fori(i,1,n) fori(j,1,n) id[i][j]=++nC;
	fori(i,1,n) fori(j,1,n) {
		int u=id[i][j];
		fori(k,0,5) {
			int v=id[i+dx[k]][j+dy[k]];
			if (v<1) continue;
			e[u].pb(v);
		}
	}

	int s=++nC, t=++nC;
	filla(color, -1);
	filla(p1, 0);
	filla(p2, 0);
	fori(i,1,n) p1[id[i][1]]=s, p1[id[i][n]]=t;
	fori(i,1,n) p2[id[1][i]]=s, p2[id[n][i]]=t;
	int turn=0;
	while (nQ--) {
		int x, y;
		cin >> x >> y;
		int u=id[x][y];
		color[u]=turn;
		if (turn==0) {
			foreach(it, e[u]) {
				if (color[*it]!=color[u]) continue;
				int ru=getRoot(u, p1), rv=getRoot(*it, p1);
				if (ru!=rv) p1[ru]=rv;
			}
			if (getRoot(s, p1)==getRoot(t, p1)) {
				cout << "ROMANS";
				return 0;
			}
		}
		else {
			foreach(it, e[u]) {
				if (color[*it]!=color[u]) continue;
				int ru=getRoot(u, p2), rv=getRoot(*it, p2);
				if (ru!=rv) p2[ru]=rv;
			}
			if (getRoot(s, p2)==getRoot(t, p2)) {
				cout << "PERSIANS";
				return 0;
			}
		}
		turn^=1;
	}
	cout << "NEITHER";

	return 0;
}