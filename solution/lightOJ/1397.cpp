#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

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


const int MAX_N = 11;
const int n = 9;
const int MAX_P=sqr(MAX_N);


int nP;
pii p[MAX_P];
char s[MAX_N];
int a[MAX_N][MAX_N], id[MAX_N][MAX_N], f[MAX_N][MAX_N];
bool r[MAX_N][MAX_N], c[MAX_N][MAX_N], b[MAX_N][MAX_N];
bool done[MAX_P];


#define ok(x, y, k, val) (!(r[x][val] || c[y][val] || b[k][val]))
#define put(x, y, k, val, state) r[x][val]=c[y][val]=b[k][val]=state;


bool tryf(int h) {
	if (h>nP) return 1;
	int minW=MAX_P, x, y, pos;
	fori(k,1,nP) if (!done[k]) {
		int i=p[k].fr, j=p[k].sc, w=0;
		fori(val,1,n) if (ok(i,j,id[i][j],val)) ++w;
		if (w<minW) {
			minW=w;
			pos=k;
			x=i, y=j;
		}
	}
	int k=id[x][y];
	done[pos]=1;
	fori(val,1,n) {
		if (!ok(x,y,k,val)) continue;
		put(x,y,k,val,1);
		f[x][y]=val;
		if (tryf(h+1)) return 1;
		f[x][y]=0;
		put(x,y,k,val,0);
	}
	done[pos]=0;
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("1397.in", "r", stdin);
	freopen("1397.out", "w", stdout);
#endif
	fori(i,1,n) fori(j,1,n) {
		int x=i/3+int(i%3>0);
		int y=j/3+int(j%3>0);
		id[i][j]=(x-1)*3+y;
	}

	int nTest;
	scanf("%d", &nTest);
	fori(testid,1,nTest) {
		nP=0;
		fori(i,1,n) {
			scanf("%s", &s);
			fori(j,1,n) {
				a[i][j]=(s[j-1]=='.')?0:s[j-1]-'0';
				if (a[i][j]==0) p[++nP]=mp(i,j);
			}
		}
		filla(r,0);
		filla(c,0);
		filla(b,0);
		filla(f, 0);
		fori(i,1,n) fori(j,1,n) {
			int x=a[i][j];
			if (x==0) continue;
			f[i][j]=a[i][j];
			b[id[i][j]][x]=r[i][x]=c[j][x]=1;
		}
		filla(done, 0);
		tryf(1);
		printf("Case %d:\n", testid);
		fori(i,1,n) {
			fori(j,1,n) printf("%d", f[i][j]);
			printf("\n");
		}
	}

	return 0;
}