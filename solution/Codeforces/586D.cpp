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


const int MAX_N = 111;
const int dx[3] = {0, +1, -1};
const int dy[3] = {1, 1, 1};


int n;
int status[MAX_N][MAX_N][MAX_N];
bool vis[MAX_N][MAX_N];
queue<pii> q;
string s;


inline bool onBoard(int x, int y) {
	if (x<1 || x>3 || y<1 || y>n) return 0;
	return 1;
}


inline bool check(int turn, int x, int y) {
	if (!onBoard(x, y)) return 0;
	if (status[turn][x][y] > 0) return 0;
	return 1;
}


bool solve(int x, int y) {
	while (!q.empty()) q.pop();
	filla(vis, 0);
	vis[x][y]=1;
	q.push(mp(x,y));
	while (!q.empty()) {
		pii u=q.front();	q.pop();
		x=u.fr, y=u.sc;
		int turn=y;
		if (y==n) return 1;
		if (y>=n && status[turn][x][y+1] != 1) return 1;
		if (status[turn][x][y+1]==1) continue;
		// if (!check(turn, x, y+1)) continue;
		fori(k,0,2) {
			int xx=x+dx[k];
			int yy=y+dy[k];
			if (!onBoard(xx, yy)) continue;
			if (status[turn][xx][yy]==1) continue;
			// if (!check(turn, xx, yy)) continue;
			if (!check(turn+1, xx, yy) || vis[xx][yy]) continue;
			vis[xx][yy]=1;
			q.push(mp(xx,yy));
		}
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("586D.in", "r", stdin);
	freopen("586D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		int x, y, K;
		cin >> n >> K;
		filla(status, 0);
		fori(i,1,3) {
			cin >> s;
			fori(j,1,n) {
				char ch=s[j-1];
				if (ch=='s') x=i, y=j;
				else if (ch!='.') status[1][i][j]=1;
			}
		}
		fori(turn,2,n) {
			bool stop=1;
			fori(i,1,3) fori(j,1,n) if (status[turn-1][i][j]==1) {
				if (j-1>0) status[turn][i][j-1]=2;
				if (j-2>0) status[turn][i][j-2]=1;
				stop=0;
			}
			if (stop) break;
		}

		if (solve(x, y)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}