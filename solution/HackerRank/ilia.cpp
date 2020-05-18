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


const int MAX_N = 5005;


int n;
int a[MAX_N];
vector<int> b;


// void solve_0() {
// 	ll right=0, acute=0, obtuse=0;
// 	fori(i,1,n) fori(j,i+1,n) fori(k,j+1,n) {
// 		if (a[i]+a[j] <= a[k]) continue;
// 		ll c = sqr(a[k]), d = sqr(a[i])+sqr(a[j]);
// 		if (c == d) ++right;
// 		else if (c < d) ++acute;
// 		else if (c < d*2) ++obtuse;
// 	}
// 	cout << acute << " " << right << " " << obtuse << endl;
// }


int find(int d) {
	if (b.empty()) return 0;
	vector<int>::iterator l = lower_bound(b.begin(), b.end(), d);
	vector<int>::iterator r = upper_bound(b.begin(), b.end(), d);
	if (l==b.end() || r==b.begin()) return 0;
	return r-l;
}


int findLessThan(int d) {
	if (b.empty()) return 0;
	vector<int>::iterator r = lower_bound(b.begin(), b.end(), d);
	return r-b.begin();
}


void solve() {
	ll right=0, acute=0, obtuse=0;
	ford(j,n-1,2) {
		b.clear();
		fori(i,j+1,n) b.pb(sqr(a[i]));
		int k=n;
		ford(i,j-1,1) {
			while (a[k]>=a[i]+a[j]) {
				--k;
				b.pop_back();
			}
			if (k<=j) break;
			ll d=sqr(a[i])+sqr(a[j]);
			ll addRight = find(d);
			ll addAcute = findLessThan(d);
			ll addObtuse = k-j - addRight - addAcute;
			right += addRight;
			acute += addAcute;
			obtuse += addObtuse;
		}
	}
	cout << acute << " " << right << " " << obtuse << endl;
}


int main() {
#ifdef DEBUG
	freopen("ilia.in", "r", stdin);
	freopen("ilia.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) cin >> a[i];
	sort(a+1, a+1+n);

	// solve_0();
	solve();

	return 0;
}