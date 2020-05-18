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


const int MAX_N=1e5+5;
const int oo=1e9+10;


struct side {
	int u,d,l,r;
	side() {}
	side(int u, int d, int l, int r) : u(u),d(d),l(l),r(r) {}
	pii get(int k) {
		if (k==1) return pii(l,u);	// top-left
		if (k==2) return pii(r,u);	// top-right
		if (k==3) return pii(l,d);	// bottom-left
		if (k==4) return pii(r,d);	// bottom-right
	}
};


int n;
pii a[MAX_N];
int ok[MAX_N];


side findSide() {
	int u=-oo,d=oo,l=oo,r=-oo;
	fori(i,1,n) if (!ok[i]) {
		l=min(l,a[i].fr);
		r=max(r,a[i].fr);
		u=max(u,a[i].sc);
		d=min(d,a[i].sc);
	}
	return side(u,d,l,r);
}


#define between(l,x,r) (l<=x && x<=r)

bool inside(int k, pii p, pii a, int len) {
	if (k==1) return between(p.fr, a.fr, p.fr+len) && between(p.sc-len, a.sc, p.sc);
	if (k==2) return between(p.fr-len, a.fr, p.fr) && between(p.sc-len, a.sc, p.sc);
	if (k==3) return between(p.fr, a.fr, p.fr+len) && between(p.sc, a.sc, p.sc+len);
	if (k==4) return between(p.fr-len, a.fr, p.fr) && between(p.sc, a.sc, p.sc+len);
}


bool tryf(int h, int len) {
	int c=0;
	fori(i,1,n) if (ok[i]) ++c;
	if (c==n) return 1;
	if (h>3) return 0;
	side s=findSide();
	fori(k,1,4) {
		pii p=s.get(k);
		fori(i,1,n) if (inside(k,p,a[i],len)) ++ok[i];
		if (tryf(h+1,len)) return 1;
		fori(i,1,n) if (inside(k,p,a[i],len)) --ok[i];
	}
	return 0;
}


bool check(int len) {
	filla(ok,0);
	if (tryf(1, len)) return 1;
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("6902.in", "r", stdin);
	freopen("6902.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n;
		fori(i,1,n) cin >> a[i].fr >> a[i].sc;
		int l=0, r=1e9/3+33, ans=r;
		while (l<=r) {
			int mid=(l+r)>>1;
			if (check(mid)) {
				ans=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		cout << ans << endl;
	}

	return 0;
}