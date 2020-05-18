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


const int MAX_N = 27;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};


struct node {
	int x1, y1, x2, y2;
	node() {}
	node(int a, int b, int c, int d) : x1(a), y1(b), x2(c), y2(d) {}
};


int n, m, xA, yA, xG, yG, xP, yP;
string a[MAX_N];
queue<node> q;
bool ok[MAX_N][MAX_N][MAX_N][MAX_N];
int d[MAX_N][MAX_N][MAX_N][MAX_N];


inline bool onBoard(int x, int y) {
	if (x<0 || y<0 || x>=n || y>=m) return 0;
	return a[x][y]!='X';
}


inline pii move(int xx, int yy, int x, int y) {
	if (y!=yy) {
		if (y<yy && onBoard(x,y+1)) return mp(x,y+1);
		else if (y>yy && onBoard(x,y-1)) return mp(x,y-1);
	}
	if (x<xx && onBoard(x+1,y)) ++x;
	else if (x>xx && onBoard(x-1,y)) --x;
	return mp(x, y);
}


int bfs() {
	filla(ok, 0);
	d[xA][yA][xG][yG]=0;
	ok[xA][yA][xG][yG]=1;
	q.push(node(xA,yA,xG,yG));
	while (!q.empty()) {
		node p=q.front();	q.pop();
		int x1=p.x1, y1=p.y1, x2=p.x2, y2=p.y2;
		if (x1==x2 && y1==y2) continue;
		if (x1==xP && y1==yP) return d[x1][y1][x2][y2];
		fori(k,0,3) {
			int x=x1+dx[k], y=y1+dy[k];
			if ((x==x2 && y==y2) || !onBoard(x, y)) continue;
			pii t=move(x,y,x2,y2);
			int xx=t.fr, yy=t.sc;
			if (x==xx && y==yy) continue;
			if (ok[x][y][xx][yy]) continue;
			ok[x][y][xx][yy]=1;
			d[x][y][xx][yy]=d[x1][y1][x2][y2]+1;
			q.push(node(x,y,xx,yy));
		}
	}
	return -1;
}


int main() {
#ifdef DEBUG
	freopen("100735C.in", "r", stdin);
	freopen("100735C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	fori(i,0,n-1) cin >> a[i];
	fori(i,0,n-1) fori(j,0,m-1) {
		if (a[i][j]=='A') xA=i, yA=j;
		else if (a[i][j]=='G') xG=i, yG=j;
		else if (a[i][j]=='P') xP=i, yP=j;
	}
	cout << bfs() << endl;

	return 0;
}