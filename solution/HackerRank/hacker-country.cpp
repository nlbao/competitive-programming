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



const ll oo = 1e18;


struct Fraction {
	ll x, y;

	inline void reduce() {
		if (y<0) y=-y, x=-x;
		ll d=__gcd(x, y);
		x/=d, y/=d;
	}

	Fraction(ll x=0, ll y=1) : x(x), y(y) {
		reduce();
	}

	bool operator < (const Fraction &o) const {
		if (x>=oo) return 0;
		if (o.x>=oo) return 1;
		return x*o.y < y*o.x;
	}

	Fraction operator + (const Fraction &o) const {
		return Fraction(x*o.y+y*o.x, y*o.y);
	}

	Fraction operator - (const Fraction &o) const {
		return Fraction(x*o.y-y*o.x, y*o.y);
	}

	Fraction operator * (const Fraction &o) const {
		return Fraction(x*o.x, y*o.y);
	}

	Fraction operator / (const Fraction &o) const {
		return (*this) * Fraction(y, x);
	}
};

Fraction getCost(const Fraction &a, ll w) {
	return (a.x==0) ? Fraction(a.x+w, 1) : Fraction(a.x+w, a.y+1);
}


const int MAX_N = 515;

int n;
int w[MAX_N][MAX_N];
ll d[MAX_N][MAX_N];


int main() {
#ifdef DEBUG
	freopen("hacker-country.in", "r", stdin);
	freopen("hacker-country.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) fori(j,1,n) cin >> w[i][j];

	fori(i,1,n) {
		fori(k,1,n) d[k][i]=oo;
		d[0][i]=0;
	}
	fori(k,1,n) fori(u,1,n) fori(v,1,n) if (v!=u) {
		d[k][v]=min(d[k][v], d[k-1][u] + w[u][v]);
	}

	Fraction ans(oo, 1);
	fori(u,1,n) {
		Fraction t(0, 1);
		fori(k,0,n-1) {
			Fraction x(d[n][u]-d[k][u], n-k);
			if (t<x) t=x;
		}
		ans=min(ans, t);
	}
	cout << ans.x << "/" << ans.y << endl;

	return 0;
}