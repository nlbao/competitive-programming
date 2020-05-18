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


inline ll read() {	ll x;   cin >> x;   return x;   }


const int LIMIT = 5000;


inline void printAns(ll n, ll a, ll b) {
	cout << n << " = ";
	fori(i,a,b) {
		cout << i;
		if (i<b) cout << " + ";
	}
	cout << endl;
}


bool solve(ll n) {
	fori(k,1,LIMIT) {
		ll t=k*(k+1)/2;
		if (t>n) break;
		if (t>1 && t==n) {
			printAns(n, 1, k);
			return 1;
		}
		if (t==n) continue;
		t=n-t;
		if (t%(k+1)!=0) continue;
		t/=(k+1);
		if (t==1 && k==1) continue;
		printAns(n, t, t+k);
		return 1;
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("6929.in", "r", stdin);
	freopen("6929.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		ll n;
		cin >> n;
		if (!solve(n)) cout << "IMPOSSIBLE\n";
	}

	return 0;
}