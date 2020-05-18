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


const int MAX_N = 1e3+3;
const int dx[9] = {-1, -1, -1, 0, 0, 0, +1, +1, +1};
const int dy[9] = {-1, 0, +1, -1, 0, +1, -1, 0, +1};


int n, m, nP;
int a[MAX_N][MAX_N], b[MAX_N][MAX_N];
pii p[sqr(MAX_N)];
bool mine[MAX_N][MAX_N];


bool cmp(const pii &a, const pii &b) {
	int da=a.fr+a.sc, db=b.fr+b.sc;
	if (da!=db) return da<db;
	if (a.fr!=b.fr && (a.fr==1 || b.fr==1)) return a.fr!=1;
	if (a.sc!=b.sc && (a.sc==1 || b.sc==1)) return a.sc!=1;
	return a.fr!=b.fr ? a.fr<b.fr : a.sc<a.sc;
}


inline void change(int x, int y, int val) {
	mine[x][y]=val;
	fori(k,0,8) b[x+dx[k]][y+dy[k]] += val;
}


void printAns() {
	fori(i,1,n) {
		fori(j,1,m) printf("%c", mine[i][j] ? 'L' : '-');
		printf("\n");
	}
}


int main() {
#ifdef DEBUG
	freopen("6849.in", "r", stdin);
	freopen("6849.out", "w", stdout);
#endif
	int nTest;
	scanf("%d", &nTest);
	fori(testid,1,nTest) {
		nP=0;
		scanf("%d%d", &n, &m);
		fori(i,1,n) fori(j,1,m) {
			scanf("%d", &a[i][j]);
			p[++nP]=mp(i,j);
		}
		sort(p+1, p+1+nP, cmp);
		if (n==1 && m==1) {
			if (a[1][1]>3) change(1,1,1);
			printAns();
			continue;
		}
		bool found=0;
		fori(u,0,1) {
			fori(v,0,1) {
				found=1;
				fori(i,1,n) fori(j,1,m) b[i][j]=0;
				change(1, 1, a[1][1]>3 ? 1 : 0);
				if (m>1) change(1,2,u);
				if (n>1) change(2,1,v);
				fori(i,1,nP) {
					int x=p[i].fr, y=p[i].sc;
					if (x+y <= 3) continue;
					if (x==1 || y==1) {
						int t=a[x][y]-b[x][y];
						if (t<0) found=0;
						else if (t<4) change(x,y,0);
						else change(x,y,1);
					}
					else {
						int t=a[x-1][y-1]-b[x-1][y-1]-(mine[x-1][y-1] ? 3 : 0);
						if (t<0 || t>1) found=0;
						else change(x,y,t);
					}
					if (!found) break;
				}
				fori(i,1,n) {
					fori(j,1,m) if (b[i][j]+(mine[i][j]?3:0)!=a[i][j]) {
						found=0;
						break;
					}
					if (!found) break;
				}
				if (found) break;
			}
			if (found) break;
		}
		printAns();
	}

	return 0;
}