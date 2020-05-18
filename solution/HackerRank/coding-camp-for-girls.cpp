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


const int MAX_N = 1e7;

int n, m;
vector<pii> ans;
bool a[MAX_N], b[MAX_N];


int main() {
#ifdef DEBUG
	freopen("coding-camp-for-girls.in", "r", stdin);
	freopen("coding-camp-for-girls.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> m;
	fori(i,1,n) a[i]=b[i]=0;
	fori(i,1,m) {
		int x, y;
		cin >> x >> y;
		a[x]=b[y]=1;
	}
	int c=0, pre;
	fori(i,1,n) {
		if (a[i]) ++c;
		if (i>1 && c>0 && pre>0 && abs(pre-c)==1) ans.pb(mp(i-1, i));
		pre=c;
		if (b[i]) --c;
	}
	sort(ans.begin(), ans.end());
	m=sz(ans);
	cout << m << endl;
	fori(i,0,m-1) cout << ans[i].fr << " " << ans[i].sc << endl;

	return 0;
}