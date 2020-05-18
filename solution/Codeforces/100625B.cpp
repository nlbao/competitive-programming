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


const int MAX_N = 18;
const int MAX_F = (1<<MAX_N) + 4;


int n, C, limit;
int a[MAX_N], id[MAX_N];
ld p[MAX_N], f[MAX_F][MAX_N];


ld solve(int mask, int need) {
	if (need==0) return 1;
	if (f[mask][need] >= 0)
		return f[mask][need];
	ld ans = 0;
	int budget=limit;
	fori(i,1,n) if (mask&id[i]) budget-=a[i];
	fori(i,1,n) if (!(mask&id[i])) {
		if (budget-a[i]<0) continue;
		int newMask = mask | id[i];
		ld success = p[i] * solve(newMask, need-1);
		ld failed = (1-p[i]) * solve(newMask, need);
		ans = max(ans, success + failed);
	}
	return f[mask][need] = ans;
}


int main() {
#ifdef DEBUG
	freopen("100625B.in", "r", stdin);
	freopen("100625B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n >> C >> limit;
		fori(i,1,n) cin >> a[i] >> p[i];
		fori(i,1,n) p[i] /= 100;
		fori(i,1,n) id[i]=1<<(i-1);
		filla(f, -1);
		cout << solve(0, C) << endl;
	}

	return 0;
}