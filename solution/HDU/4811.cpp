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


inline ll solve(ll x, ll y, ll z) {
	if (x==0) {
		if (y==0) {
			if (z==0) return 0;
			else if (z==1) return 0;
			return 1LL + (z-2)*2;
		}
		if (z==1) return 1;
		if (y==1) return 3 + (z-2)*3;
		return 6LL + (y-2+z-2)*4;
	}
	if (x==1) {
		if (y==1) {
			if (z==1) return 3;
			return 6LL + (z-2)*4;
		}
		return 10LL + (y-2+z-2)*5;
	}
	return 15LL + (x+y+z-6)*6;
}


int main() {
#ifdef DEBUG
	freopen("4811.in", "r", stdin);
	freopen("4811.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	ll x, y, z;
	while (cin >> x >> y >> z) {
		if (x>y) swap(x, y);
		if (x>z) swap(x, z);
		if (y>z) swap(y, z);
		cout << solve(x, y, z) << endl;
	}

	return 0;
}