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


const int MAX_A = 26;


int a[MAX_A+2];


int find_max_len() {
	int ans = 0;
	bool has1 = false;
	for (int i = 0; i < MAX_A; ++i) {
		if (a[i] >= 2) ans += 2;
		else if (a[i] == 1) has1 = true;
	}
	return ans + int(has1);
}


int count_strings() {
	int cnt1 = 0, minCnt2 = 1e9, cnt2 = 0;
	for (int i = 0; i < MAX_A; ++i) {
		if (a[i] >= 2) {
			minCnt2 = min(minCnt2, a[i]/2);
			++cnt2;
		}
		else if (a[i] == 1) ++cnt1;
	}
	if (cnt1 > 0) return min(cnt1, minCnt2);
	if (cnt2 == 0) return 0;
	return minCnt2;
}


int main() {
#ifdef DEBUG
	freopen("101972F.in", "r", stdin);
	freopen("101972F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	while (nTest--) {
		for (int i = 0; i < MAX_A; ++i)
			cin >> a[i];
		cout << find_max_len() << " " << count_strings() << endl;
	}

	return 0;
}