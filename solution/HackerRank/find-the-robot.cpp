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
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }

const ll dx[4] = {+1, 0, -1, 0};
const ll dy[4] = {0, +1, 0, -1};


int x0[4] = {1, 2, 3, 4};


inline ll cal(ll x0, ll k) {
	ll xn = x0 + (k-1)*4;
	return (x0+xn) * k / 2;
}


int main() {
#ifdef DEBUG
	freopen("find-the-robot.in", "r", stdin);
	freopen("find-the-robot.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	fori(testid,1,nTest) {
		ll n, x = 0, y = 0;
		cin >> n;
		fori(i,0,3) {
			if (n < 1) break;
			ll r = n/4;
			if ((n%4) != 0) ++r;
			ll d = cal(x0[i], r);
			--n;
			x += dx[i]*d;
			y += dy[i]*d;
		}
		cout << x << " " << y << endl;
	}

	return 0;
}