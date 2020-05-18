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


const int MAX_N = 111;


int n;
string s[MAX_N];


bool check(const string &s, int x, int y) {
	fori(i,0,sz(s)-1) {
		char k=s[i]-'a';
		if (k!=x && k!=y) return 0;
	}
	return 1;
}

int solve(int x, int y) {
	int ans=0;
	fori(i,1,n) {
		if (check(s[i], x, y)) ans += sz(s[i]);
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("593A.in", "r", stdin);
	freopen("593A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) cin >> s[i];
	int ans = 0;
	fori(x,0,30) fori(y,0,30) ans=max(ans, solve(x, y));
	cout << ans << endl;

	return 0;
}