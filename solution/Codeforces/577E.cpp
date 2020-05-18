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


const int MAX_N = 1e6+6;
const int MAX_K = 1e3+6;
const int D = 1e3;


vector<int> b[MAX_K][MAX_K];


inline void printB(int x, int y) {
	foreach(it, b[x][y]) printf("%d ", *it);
}


int main() {
#ifdef DEBUG
	freopen("577E.in", "r", stdin);
	freopen("577E.out", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	fori(i,1,n) {
		int x, y;
		scanf("%d%d", &x, &y);
		x /= D;
		y /= D;
		b[x][y].pb(i);
	}
	int c=0;
	fori(i,0,MAX_K-1) {
		if (c) {
			fori(j,0,MAX_K-1) printB(i, j);
		}
		else {
			ford(j,MAX_K-1,0) printB(i, j);
		}
		c^=1;
	}

	return 0;
}