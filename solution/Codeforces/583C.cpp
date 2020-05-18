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


const int MAX_N = 515;
const int MAX_M = sqr(MAX_N);


int n, m;
int a[MAX_M], ans[MAX_N];
multiset<int> heap;


void solve() {
	heap.clear();
	int p=1;
	fori(i,1,n) {
		while (!heap.empty() && -*heap.begin()==a[p]) {
			heap.erase(heap.begin());
			++p;
			continue;
		}
		ans[i]=a[p];
		fori(j,1,i-1) {
			int d=__gcd(ans[j], ans[i]);
			fori(x,0,1) heap.insert(-d);
		}
		++p;
	}
}


int main() {
#ifdef DEBUG
	freopen("583C.in", "r", stdin);
	freopen("583C.out", "w", stdout);
#endif
	scanf("%d", &n);
	m=n*n;
	fori(i,1,m) {
		scanf("%d", &a[i]);
		a[i]=-a[i];
	}
	sort(a+1,a+1+m);
	fori(i,1,m) a[i]=-a[i];
	solve();
	fori(i,1,n) printf("%d ", ans[i]);

	return 0;
}