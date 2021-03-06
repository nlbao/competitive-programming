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


const int MAX_N=2e5+5;

int n;
pii a[MAX_N];
int ans[MAX_N];
set<pii> heap;


int main() {
#ifdef DEBUG
	freopen("100090I.in", "r", stdin);
	freopen("100090I.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) {
		int x, y;
		cin >> x >> y;
		a[i] = mp(x,y);
	}
	int k=0, i=1;
	heap.clear();
	while (i<=n || !heap.empty()) {
		++k;
		if (i<=n) {
			if (heap.empty()) k=max(k, a[i].fr);
			while (i<=n && a[i].fr<=k) {
				heap.insert(pii(-(a[i].sc-a[i].fr), i));
				++i;
			}
		}
		ans[heap.begin()->sc]=k;
		heap.erase(heap.begin());
	}
	fori(i,1,n) cout << ans[i] << " ";

	return 0;
}