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


const int MIN_V = 20110000;
const int MAX_V = 20159999;
const int MAX_Y = MAX_V-MIN_V+10;
const int MAX_N = 20;


int ID, point[MAX_N];
string strID, a[MAX_N], b[MAX_Y];


struct Matching {
	static const int MAX_N = 2e5 + 55;

	int nx, ny, mx[MAX_N], my[MAX_N], d[MAX_N];
	vector<int> e[MAX_N];
	queue<int> q;
	bool useX[MAX_N], useY[MAX_N];

	void init(int x, int y) {
		nx = x, ny = y;
		for (int i = 0; i <= nx; ++i)
			e[i].clear();
		fori(i,0,nx) useX[i]=1;
		fori(i,0,ny) useY[i]=1;
	}

	void addEdge(int u, int v) {
		e[u].push_back(v);
	}

	void changeX(int u, bool val) {	useX[u]=val;	}
	void changeY(int u, bool val) {	useY[u]=val;	}

	bool bfs_matching() {
		while (!q.empty()) q.pop();
		for (int i = 1; i <= nx; ++i)
			if (useX[i] && !mx[i]) {
				d[i] = 1;
				q.push(i);
			}
			else d[i] = 0;
		d[0] = 0;
		while (!q.empty()) {
			int u = q.front();  q.pop();
			foreach(it, e[u]) {
				int v = *it;
				if (!useY[v] || !useX[my[v]]) continue;
				if (!d[my[v]]) {
					d[my[v]] = d[u] + 1;
					if (!my[v]) return true;
					q.push(my[v]);
				}
			}
		}
		return false;
	}

	bool dfs_matching(int u) {
		if (u == 0) return true;
		foreach(it, e[u]) {
			int v = *it;
			if (!useY[v] || !useX[my[v]]) continue;
			if (d[my[v]] == d[u]+1 && dfs_matching(my[v])) {
				mx[u] = v;
				my[v] = u;
				return true;
			}
		}
		d[u] = 0;
		return false;
	}

	int getMatch() {
		int ans = 0;
		filla(mx, 0);
		filla(my, 0);
		while (bfs_matching())
			for (int i = 1; i <= nx; ++i)
				if (useX[i] && !mx[i] && dfs_matching(i))
					++ans;
		return ans;
	}
};


Matching matching;


string toString(int x) {
	stringstream ss;
	ss << x;
	return ss.str();
}


inline bool check(const string &a, const string &b) {
	int n=sz(a);
	fori(i,0,n-1) {
		if (a[i]=='?' || b[i]=='?') continue;
		if (a[i]!=b[i]) return 0;
	}
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("100687B.in", "r", stdin);
	freopen("100687B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nX=read();
	cin >> ID;
	fori(i,1,nX)
		cin >> a[i] >> point[i];
	strID=toString(ID);

	int nY=MAX_V-MIN_V+1;
	matching.init(nX, nY);
	for (int i=1; i<=nY; ++i) {
		stringstream ss;
		ss << MIN_V+i-1;
		ss >> b[i];
		if (b[i]==strID) matching.changeY(i, 0);
	}

	fori(i,1,nX) fori(j,1,nY) if (check(a[i], b[j])) {
		matching.addEdge(i, j);
	}

	int ans=0;
	fori(i,1,nX) {
		if (!check(strID, a[i])) continue;
		matching.changeX(i, 0);
		int c=matching.getMatch();
		if (c==nX-1) ans=max(ans, point[i]);
		matching.changeX(i, 1);
	}
	cout << ans << endl;

	return 0;
}