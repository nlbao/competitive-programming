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


const int MAX_N = sqrt(1e9+7)+4;


int nP, n;
int p[MAX_N];
bool ok[MAX_N];


inline bool isPrime(int x) {
	if (x<2) return 0;
	if (x==2 || x==3) return 1;
	fori(i,1,nP) {
		ll t=p[i];
		if (t*t>x) break;
		if ((x%t)==0) return 0;
	}
	return 1;
}


void solve(int n) {
	if (isPrime(n)) {
		cout << 1 << endl << n << endl;
		return;
	}
	if (isPrime(n-2)) {
		cout << 2 << endl << 2 << " " << n-2 << endl;
		return;
	}
	cout << 3 << endl;
	fori(i,1,nP) fori(j,i,nP) if (isPrime(n-p[i]-p[j])) {
		cout << p[i] << " " << p[j] << " " << n-p[i]-p[j] << endl;
		return;
	}
}


int main() {
#ifdef DEBUG
	freopen("584D.in", "r", stdin);
	freopen("584D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	nP=0;
	filla(ok, 1);
	ok[0]=ok[1]=0;
	fori(i,2,MAX_N-1) if (ok[i]) {
		p[++nP]=i;
		for (ll j=i*i; j<MAX_N; j+=i)
			ok[j]=0;
	}

	cin >> n;
	solve(n);

	return 0;
}