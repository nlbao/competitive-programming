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


const int MAX_N = 1e3+3;

set<int> s[MAX_N];


int main() {
#ifdef DEBUG
	freopen("possible-maximum.in", "r", stdin);
	freopen("possible-maximum.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	fori(i,1,MAX_N-1) {
		s[i]=s[i-1];
		fori(j,1,i-1) s[i].insert(i&j);
	}

	int nTest=read();
	while (nTest--) {
		int n, k;
		cin >> n >> k;
		set<int>::iterator it=s[n].lower_bound(k);
		if (it==s[n].end()) --it;
		while (*it>=k) --it;
		cout << *it << endl;
	}

	return 0;
}