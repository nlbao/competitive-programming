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


const int MAX_N = 33;
const int MAX_P = sqr(MAX_N);


int n, m, cnt, nP, minX, minY;
int a[MAX_N][MAX_N], b[MAX_N][MAX_N];
pii pos[MAX_P];


bool change(int x, int y, int len, int val) {
	int lx=x-len, ly=y-len, rx=x+len, ry=y+len;
	if (val>0) {
		if (lx<1 || ly<1 || rx>n || ry>m) return 0;
		fori(i,lx,rx) if (b[i][y]+1>a[i][y]) return 0;
		fori(j,ly,ry) if (b[x][j]+1>a[x][j]) return 0;
	}
	fori(i,lx,rx) b[i][y]+=val;
	fori(j,ly,ry) b[x][j]+=val;
	b[x][y]-=val;
	return 1;
}


bool tryf(int k) {
	if (k>nP) {
		fori(i,1,n) fori(j,1,m) if (b[i][j]!=a[i][j]) return 0;
		return 1;
	}
	int x=pos[k].fr, y=pos[k].sc;
	if (b[x][y]==0)
		fori(len,1,5) {
			if (change(x, y, len, 1)) {
				++cnt;
				if (tryf(k+1)) {
					if (x>minX || x==minX && y>minY)
						minX=x, minY=y;
					return 1;
				}
				change(x, y, len, -1);
				--cnt;
			}
		}
	if (tryf(k+1)) return 1;
}


int main() {
#ifdef DEBUG
	freopen("6850.in", "r", stdin);
	freopen("6850.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> m;
		fori(i,1,n) fori(j,1,m) cin >> a[i][j];
		nP=0;
		ford(i,n,1) ford(j,m,1) if (a[i][j]==1) pos[nP++]=mp(i, j);
		cnt = minX = minY = 0;
		filla(b, 0);
		tryf(1);
		cout << cnt << endl;
		cout << minX << " " << minY << endl;
	}

	return 0;
}