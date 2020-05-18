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


ll A, B, S1, S2, S3;


bool check_1(ll a, ll b) {
	if (S1%b != 0 || S2%b != 0 || S3%b != 0)
		return 0;
	ll a1 = S1 / b;
	ll a2 = S2 / b;
	ll a3 = S3 / b;
	if (a1+a2+a3 != a) return 0;
	return 1;
}


bool check_2(ll a, ll b, ll s, ll S1, ll S2) {
	if (s%b != 0) return 0;
	ll a0 = s / b;
	ll a1 = a - a0;
	if (a1 <= 0) return 0;
	if (S1%a1 != 0 || S2%a1 != 0) return 0;
	ll b1 = S1 / a1;
	ll b2 = S2 / a1;
	if (b1+b2 != b) return 0;
	return 1;
}


bool solve() {
	// case 1
	if (check_1(A, B)) return 1;
	if (check_1(B, A)) return 1;
	// case 2
	if (check_2(A, B, S1, S2, S3)) return 1;
	if (check_2(A, B, S2, S3, S1)) return 1;
	if (check_2(A, B, S3, S1, S2)) return 1;
	// case 3
	if (check_2(B, A, S1, S2, S3)) return 1;
	if (check_2(B, A, S2, S3, S1)) return 1;
	if (check_2(B, A, S3, S1, S2)) return 1;
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("VCAKE.in", "r", stdin);
	freopen("VCAKE.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest = read();
	while (nTest--) {
		cin >> B >> A >> S1 >> S2 >> S3;
		if (solve()) cout << "Yes\n";
		else cout << "No\n";
	}

	return 0;
}