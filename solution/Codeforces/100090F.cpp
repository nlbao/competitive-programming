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


const int MAX_N = 2e5+5;

int h[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100090F.in", "r", stdin);
	freopen("100090F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	ll n, ans=0;
	cin >> n;
	set<int> q;
	set<int>::iterator it, it2;
	fori(i,1,n) {
		int u;
		cin >> u;
		h[u]=0;
		it=q.lower_bound(u);
		if (it != q.begin()) {
			it2 = it;
			--it2;
			h[u]=max(h[u], h[*it2]+1);
		}
		if (it != q.end()) {
			h[u]=max(h[u], h[*it]+1);
		}
		q.insert(u);
		ans += h[u];
	}
	cout << ans << endl;

	return 0;
}