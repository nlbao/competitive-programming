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


const int MAX_A = 1e4+44;

bool ok[MAX_A];


int main() {
#ifdef DEBUG
	freopen("consecutive-numbers.in", "r", stdin);
	freopen("consecutive-numbers.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		int n;
		cin >> n;
		filla(ok, 0);
		fori(i,1,n) {
			int x;
			cin >> x;
			ok[x]=1;
		}
		int ans=0;
		for (int i=1, j=1; i<MAX_A; i=j) {
			if (!ok[i]) {
				++j;
				continue;
			}
			while (j<MAX_A && ok[j]) ++j;
			ans=max(ans, j-i);
		}
		cout << ans << endl;
	}

	return 0;
}