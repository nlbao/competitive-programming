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
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 444;
const int LIM_DIRTINESS = 20;


int n;
int d[MAX_N], hasPush[MAX_N];


int solve() {
	int ans = 0;
	int push_cnt = 0;
	int dirtiness = 0;
	for (int i = 1; i <= 365; ++i) {
		int add = push_cnt;
		dirtiness += add;
		if (dirtiness >= LIM_DIRTINESS) {
			++ans;
			push_cnt = 0;
			dirtiness = 0;
		}
		push_cnt += hasPush[i];
	}
	if (push_cnt > 0) ++ans;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("101933A.in", "r", stdin);
	freopen("101933A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	filla(hasPush, 0);
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
		hasPush[d[i]] = 1;
	}
	cout << solve() << endl;

	return 0;
}