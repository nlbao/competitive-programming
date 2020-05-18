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
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


const int MAX_N = 1e6+16;
const ll BASE = 1e4+7;


int n;
char s[MAX_N];
ll p[MAX_N], h[MAX_N], g[MAX_N];
map<ll, ll> sall, sg, sh;


inline ll getH(int i, int j) {
	return i==0 ? h[j] : h[j]-h[i-1]*p[j-i+1];
}

inline ll getG(int i, int j) {
	return j==n-1 ? g[i] : g[i]-g[j+1]*p[j-i+1];
}

inline bool isPalin(int i, int j) {
	if (i>=j) return 1;
	return getH(i,j)==getG(i,j);
}

inline void build() {
	h[0]=s[0];
	g[n-1]=s[n-1];
	fori(i,1,n-1) h[i]=h[i-1]*BASE+s[i];
	ford(i,n-2,0) g[i]=g[i+1]*BASE+s[i];
}


int main() {
#ifdef DEBUG
	freopen("PP.in", "r", stdin);
	freopen("PP.out", "w", stdout);
#endif
	p[0]=1;
	fori(i,1,MAX_N-1) p[i]=p[i-1]*BASE;

	int nTest;
	scanf("%d", &nTest);
	while (nTest--) {
		ll ans=0;
		int nString;
		scanf("%d", &nString);
		sall.clear();
		sh.clear();
		sg.clear();
		while (nString--) {
			scanf("%s", s);
			n=strlen(s);
			build();
			// BA
			fori(i,0,n-1) if (isPalin(i+1,n-1)) ans += sall[getG(0, i)];
			ans += sg[h[n-1]];
			// AB
			ford(i,n-1,0) if (isPalin(0,i-1)) ans += sall[g[i]];
			ans += sh[g[0]];
			// update
			sall[h[n-1]] += 1;
			fori(i,0,n-2) if (isPalin(i+1, n-1)) sh[h[i]] += 1;
			ford(i,n-1,1) if (isPalin(0, i-1)) sg[g[i]] += 1;
		}
		printf("%lld\n", ans);
	}

	return 0;
}