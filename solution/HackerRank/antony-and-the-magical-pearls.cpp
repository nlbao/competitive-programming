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


const ll MOD = 1e9+7;


multiset<ll> s;
priority_queue<ll, vector<ll>, greater<ll> > heap;


int main() {
#ifdef DEBUG
	freopen("antony-and-the-magical-pearls.in", "r", stdin);
	freopen("antony-and-the-magical-pearls.out", "w", stdout);
#endif
	// fori(i,1,10) heap.push(i);
	// fori(i,1,10) {
	// 	cout << heap.top() << endl;
	// 	heap.pop();
	// }

	int n;
	scanf("%d", &n);
	fori(i,1,n) {
		ll a;
		scanf("%lld", &a);
		// s.insert(a);
		heap.push(a);
	}
	ll ans=0, x, y;
	fori(i,1,n-1) {
		// ll x=*s.begin();	s.erase(s.begin());
		// ll y=*s.begin();	s.erase(s.begin());
		x=heap.top();	heap.pop();
		y=heap.top();	heap.pop();
		x+=y;
		while (x>=MOD) x-=MOD;
		// x%=MOD;
		// ans=(ans+x)%MOD;
		ans+=x;
		while (ans>=MOD) ans-=MOD;
		// s.insert(x);
		heap.push(x);
	}
	printf("%lld\n", ans);

	return 0;
}