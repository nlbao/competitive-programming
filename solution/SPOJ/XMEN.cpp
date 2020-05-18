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


const int MAX_N = 1e5+55;


int n;
int a[MAX_N], b[MAX_N], p[MAX_N], f[MAX_N];


void update(int i, int val) {
	for (; i<=n; i+=lowbit(i)) f[i]=max(f[i], val);
}

int get(int i) {
	int ans=0;
	for (; i>0; i-=lowbit(i)) ans=max(ans, f[i]);
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("XMEN.in", "r", stdin);
	freopen("XMEN.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n;
		fori(i,1,n) {
			cin >> a[i];
			p[a[i]] = i;
		}
		fori(i,1,n) cin >> b[i];
		filla(f, 0);
		int ans=0;
		fori(i,1,n) {
			int x = b[i], k = p[x];
			int t = get(k-1) + 1;
			ans = max(ans, t);
			update(k, t);
		}
		cout << ans << endl;
	}

	return 0;
}