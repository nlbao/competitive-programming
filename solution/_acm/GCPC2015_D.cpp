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


const int MAX_W = 222;
const int MAX_N = 10;


int n, m, W, H, S;
pii a[MAX_N];
bool f[MAX_W][MAX_W], ok[MAX_N], use[MAX_N];


inline bool tryFill(int x, int y, int h, int w, bool val) {
	int xx=x+h-1, yy=y+w-1;
	if (xx > H || yy > W) return 0;
	fori(i,x,xx) fori(j,y,yy) if (f[i][j]==val) return 0;
	fori(i,x,xx) fori(j,y,yy) f[i][j]=val;
	return 1;
}


bool tryf() {
	int x=-1, y=-1;
	fori(i,1,H) {
		if (x>-1) break;
		fori(j,1,W) if (!f[i][j]) {
			x=i, y=j;
			break;
		}
	}
	if (x==-1) return 1;
	fori(i,1,n) if (use[i] && ok[i])
		fori(k,0,1) {
			swap(a[i].fr, a[i].sc);
			ok[i]=0;
			if (tryFill(x, y, a[i].fr, a[i].sc, 1)) {
				if (tryf()) return 1;
				tryFill(x, y, a[i].fr, a[i].sc, 0);
			}
			ok[i]=1;
		}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("GCPC2015_D.in", "r", stdin);
	freopen("GCPC2015_D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);
	cin >> W >> H >> m;
	n=0;
	fori(i,1,m) {
		int c, x, y;
		cin >> c >> x >> y;
		while(c--) a[++n]=pii(x,y);
	}

	S = W*H;
	bool ans=0;
	int nMask=(1<<n);
	fori(mask,1,nMask-1) {
		int t=0;
		filla(use, 0);
		fori(i,1,n) if (mask&(1<<(i-1))) {
			use[i]=1;
			t+=a[i].fr*a[i].sc;
			if (t>S) break;
		}
		if (t!=S) continue;
		filla(f, 0);
		filla(ok, 1);
		if (tryf()) {
			ans=1;
			break;
		}
	}
	if (ans) cout << "yes\n";
	else cout << "no\n";

	return 0;
}