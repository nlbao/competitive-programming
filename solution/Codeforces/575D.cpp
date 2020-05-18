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


int main() {
#ifdef DEBUG
	freopen("575D.in", "r", stdin);
	freopen("575D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	vector<pair<pii, pii> > ans;
	fori(i,1,1000) ans.pb(mp(mp(i,1), mp(i,2)));
	ford(i,1000,1) ans.pb(mp(mp(i,1), mp(i,2)));
	int n=sz(ans);
	cout << n << endl;
	fori(i,0,n-1) {
		cout << ans[i].fr.fr << " " << ans[i].fr.sc << " ";
		cout << ans[i].sc.fr << " " << ans[i].sc.sc << endl;
	}

	return 0;
}