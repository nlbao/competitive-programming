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
#define has(a, x) (a.find(x) != a.end())
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+55;


int n;
int a[MAX_N], b[MAX_N];


ll solve() {
	int c[2]={0, 0};
	fori(i,1,n) c[b[i]]+=a[i];
	if (c[0]==0 || c[1]==0) return c[0]+c[1];
	ll d=__gcd(c[0], c[1]);
	ll ans=0, tx=c[0]/d, ty=c[1]/d, x=0, y=0;
	fori(i,1,n) {
		if (b[i]==0) {
			bool ck=1;
			if (y==0 || x*ty >= y*tx) ck=0;
			if (ck==1 && (tx*y)%ty!=0) ck=0;
			if (ck==1) {
				ll d=tx*y/ty-x;
				if (1<=d && d<=a[i]) {
					++ans;
					x=a[i]-d;
					y=0;
				}
				else ck=0;
			}
			if (!ck) x+=a[i];
		}
		else {
			bool ck=1;
			if (x==0 || x*ty <= y*tx) ck=0;
			if (ck==1 && (ty*x)%tx!=0) ck=0;
			if (ck==1) {
				ll d=ty*x/tx-y;
				if (1<=d && d<=a[i]) {
					++ans;
					y=a[i]-d;
					x=0;
				}
				else ck=0;
			}
			if (!ck) y+=a[i];
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("6935.in", "r", stdin);
	freopen("6935.out", "w", stdout);
#endif
	int nTest=read();
	fori(testid,1,nTest) {
		scanf("%d", &n);
		fori(i,1,n) {
			char ch;
			scanf("%d%c", &a[i], &ch);
			scanf("%c", &ch);
			b[i]=(ch=='W');
		}
		printf("%lld\n", solve());
	}

	return 0;
}