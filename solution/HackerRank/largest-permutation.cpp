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


const int MAX_N = 1e5+5;

int a[MAX_N], p[MAX_N];


int main() {
#ifdef DEBUG
	freopen("largest-permutation.in", "r", stdin);
	freopen("largest-permutation.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n, k;
	cin >> n >> k;
	fori(i,1,n) {
		cin >> a[i];
		p[a[i]]=i;
	}
	int x=n;
	fori(i,1,n) {
		if (k<1) break;
		int j=p[x];
		if (j!=i) {
			int y=a[i];
			swap(a[i], a[j]);
			swap(p[x], p[y]);
			--k;
		}
		--x;
	}
	fori(i,1,n) cout << a[i] << " ";

	return 0;
}