#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define forr(i,a,b) for (__typeof(b) i=(a); i!=(b)+((a)<(b)?1:-1); i+=((a)<(b)?1:-1))
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


inline ll read() {	ll x;   cin >> x;   return x;   }


int x, y, z;


bool solve() {
	if (x<1||y<1||z<1) return 0;
	return x+y+z==180;
}


int main() {
#ifdef DEBUG
	freopen("100676B.in", "r", stdin);
	freopen("100676B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	forr(testid,1,nTest) {
		cin >> x >> y >> z;
		if (solve()) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}