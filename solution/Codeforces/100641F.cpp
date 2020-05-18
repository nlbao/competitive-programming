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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_R = 111;
const int MAX_N = sqr(MAX_R)+4;
const char dir[4] = {'E', 'N', 'S', 'W'};
const int dx[4] = {0, -1, +1, 0};
const int dy[4] = {+1, 0, 0, -1};
const int oo = 1e9;


int n, nR, nC;
vector<int> e[MAX_N], e2[MAX_N];
int id[MAX_R][MAX_R], d[MAX_N], f[MAX_N], g[MAX_N], q[MAX_N];


pii convert(const string &s) {
	int i=0, l=0, k=0;
	while (isdigit(s[i])) l=l*10+s[i++]-'0';
	while (s[i]!=dir[k]) ++k;
	return mp(l,k);
}


int getNode(int i, int j, int len, int k) {
	i+=dx[k]*len;
	j+=dy[k]*len;
	if (i<1||j<1||i>nR||j>nC) return -1;
	return id[i][j];
}


void bfs(int s, vector<int> e[MAX_N]) {
	fori(i,1,n) d[i]=oo;
	d[s]=(s==n)?0:1;
	int l=1, r=1;
	q[1]=s;
	while (l<=r) {
		int u=q[l++];
		foreach(it, e[u]) {
			int v=*it;
			if (d[v]<oo) continue;
			d[v]=d[u]+((v==n)?0:1);
			q[++r]=v;
		}
	}
}


int solve() {
	int minD=f[n], minI, minJ, minL, minK;
	int maxLen=max(nR, nC);
	fori(i,1,nR) fori(j,1,nC) {
		if (i==nR && j==nC) continue;
		int u=id[i][j];
		fori(len,1,maxLen) fori(k,0,3) {
			int v=getNode(i,j,len,k);
			if (v<0) continue;
			int tmp=f[u]+g[v];
			if (tmp<minD) {
				minD=tmp;
				minI=i, minJ=j;
				minL=len, minK=k;
			}
		}
	}
	if (minD==f[n]) {
		if (f[n]>=oo) return -1;
		return 0;
	}
	cout << minI-1 << " " << minJ-1 << " " << minL << dir[minK] << " " << minD;
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("100641F.in", "r", stdin);
	freopen("100641F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int testid=0;
	string s;
	while (1) {
		cin >> nR >> nC;
		if (nR==0) break;
		n=0;
		fori(i,1,nR) fori(j,1,nC) {
			id[i][j]=++n;
			e[n].clear();
			e2[n].clear();
		}
		fori(i,1,nR) fori(j,1,nC) {
			if (i==nR && j==nC) continue;
			cin >> s;
			pii t=convert(s);
			int u=id[i][j], v=getNode(i,j,t.fr,t.sc);
			if (v>0) e[u].pb(v), e2[v].pb(u);
		}

		cout << "Case " << ++testid << ": ";
		bfs(1, e);
		fori(i,1,n) f[i]=d[i];
		bfs(n, e2);
		fori(i,1,n) g[i]=d[i];
		int t=solve();
		if (t==-1) cout << "impossible";
		else if (t==0) cout << "none " << f[n];
		cout << endl;
	}

	return 0;
}