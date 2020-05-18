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


const int MAX_N = 1e6+6;

int n;
int a[MAX_N];
set<int> s[MAX_N];
bool ok[MAX_N];


int main() {
#ifdef DEBUG
	freopen("BALONI.in", "r", stdin);
	freopen("BALONI.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) {
		cin >> a[i];
		s[a[i]].insert(i);
	}
	int ans=0;
	filla(ok, 1);
	fori(i,1,n) if (ok[i]) {
		++ans;
		int x=i;
		while (ok[x]) {
			ok[x]=0;
			s[a[x]].erase(x);
			set<int>::iterator it = s[a[x]-1].lower_bound(x);
			if (it!=s[a[x]-1].end()) x=*it;
		}
	}
	cout << ans << endl;

	return 0;
}