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


struct Seg {
	int x, y;
	bool type;
	Seg() {}
	Seg(int x, int y, bool type) : x(x), y(y), type(type) {}
	bool operator < (const Seg &o) const {
		if (x!=o.x) return x<o.x;
		return type<o.type;
	}
};


const int MAX_N = 1004;
const int oo = 1e9;


int n, m;
pii a[MAX_N];
vector<Seg> s, b;
set<int> c;


int main() {
#ifdef DEBUG
	freopen("100733J.in", "r", stdin);
	freopen("100733J.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	fori(i,1,n) {
		int x, y;
		cin >> y >> x;
		a[i]=mp(x, y);
	}
	fori(i,1,m) {
		int y, x1, x2;
		cin >> y >> x1 >> x2;
		s.pb(Seg(x1, y, 0));
		s.pb(Seg(x2, y, 1));
	}
	sort(s.begin(), s.end());
	fori(i,1,n) {
		int x=a[i].fr, y=a[i].sc;
		int top=0, bot=0, l=oo, r=oo;
		foreach(it, s) {
			if (it->y<y) {
				if (!it->type) ++bot;
				else --bot;
			}
			else {
				if (!it->type) ++top;
				else --top;
			}
			if (bot && top && l==oo)
				l=it->x-x;
			if ((!bot || !top) && l!=oo) {
				r=it->x-x;
				b.pb(Seg(l, i, 0));
				b.pb(Seg(r, i, 1));
				l=r=oo;
			}
		}
	}

	int ans=0;
	sort(b.begin(), b.end());
	foreach(it, b) {
		if (!it->type) c.insert(it->y);
		ans=max(ans, sz(c));
		if (it->type) c.erase(it->y);
	}
	cout << ans << endl;
	return 0;
}