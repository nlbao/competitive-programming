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


int main() {
#ifdef DEBUG
	freopen("100623C.in", "r", stdin);
	freopen("100623C.out", "w", stdout);
#else
	freopen("class.in", "r", stdin);
	freopen("class.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n, r, c;
	cin >> n >> r >> c;
	int x=0;
	while ((x+1)<=r && (x+1)<=c && 2*(x+1)<=n+1) ++x;
	cout << x << endl;
	n-=2*x-1;
	fori(i,1,r) {
		fori(j,1,c) {
			if (i==1 && j<=x) cout << "#";
			else if (j==1 && i<=x) cout << "#";
			else if (n>0) {
				cout << "#";
				--n;
			}
			else cout << ".";
		}
		cout << endl;
	}

	return 0;
}