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


const int MAX_N = 5e4+44;


pii a[MAX_N];
ll s[MAX_N];


int main() {
#ifdef DEBUG
	freopen("STDPRGS.in", "r", stdin);
	freopen("STDPRGS.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n;
	cin >> n;
	fori(i,1,n) {
		int x;
		cin >> x;
		a[i]=mp(x, i);
	}
	int blockSize = sqrt(n);
	// nBlock = (n / blockSize) + int(n%blockSize > 0);
	// nBlock = 0;
	for (int i = 1, c=1; i <= n; i += blockSize, ++c) {
		int j = min(i+blockSize-1, n);
		sort(a+i, a+j+1);
		s[c]=0;
		fori(k,i+1,j) s[c] += sqr(a[k].fr-a[k-1].fr);

		cout << i << " " << j << ": " << s[c] << endl;	
	}

	int nQ=read();
	while (nQ--) {
		int l, r;
		cin >> l >> r;
		ll ans=0, pre=-1;
		for (int i = 1, c=1; i <= n; i += blockSize, ++c) {
			int j = min(i+blockSize-1, n);
			if (j<l) continue;
			if (i>r) break;
			if (l<=i && j<=r) {
				ans += s[c];
				if (pre>-1) ans += sqr(a[i].fr-pre);
				pre=a[j].fr;
				continue;
			}
			fori(k,i,j) if (l <= a[k].sc && a[k].sc <= r) {
				if (pre>-1) ans += sqr(a[k].fr-pre);
				pre=a[k].fr;
			}
		}
		cout << ans << endl;
	}

	return 0;
}