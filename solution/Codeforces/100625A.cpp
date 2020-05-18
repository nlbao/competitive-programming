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


struct Car {
	int p, q, k;
	Car () {}
	Car (int p, int q, int k) : p(p), q(q), k(k) {}
};


struct Spy {
	string carName;
	int status;
	ll cost;
	Spy() {
		carName="";
		status = 0;
		cost = 0;
	}
};


map<string, Car> car;
map<string, Spy> spy;


int main() {
#ifdef DEBUG
	freopen("100625A.in", "r", stdin);
	freopen("100625A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	string s;
	while (nTest--) {
		int nCar, nSpy;
		cin >> nCar >> nSpy;
		car.clear();
		fori(i,1,nCar) {
			int p, q, k;
			cin >> s >> p >> q >> k;
			car[s] = Car(p, q, k);
		}
		spy.clear();
		fori(i,1,nSpy) {
			int t;
			char e;
			cin >> t >> s >> e;
			if (!has(spy, s)) spy[s] = Spy();
			if (e == 'p') {
				string C;
				cin >> C;
				if (spy[s].status != 0) spy[s].status = -1;
				if (spy[s].status < 0) continue;
				spy[s].carName = C;
				spy[s].cost += car[C].q;
				spy[s].status = 1;
			}
			else if (e == 'r') {
				int d;
				cin >> d;
				if (spy[s].status != 1) spy[s].status = -1;
				if (spy[s].status < 0) continue;
				spy[s].cost += d * car[spy[s].carName].k;
				spy[s].status = 0;
			}
			else {
				int p;
				cin >> p;
				if (spy[s].status != 1) spy[s].status = -1;
				if (spy[s].status < 0) continue;
				ll tmp = 1LL * p * car[spy[s].carName].p;
				if (tmp % 100 == 0) spy[s].cost += tmp / 100;
				else spy[s].cost += ceil(tmp / 100.0);
			}
		}
		foreach(it, spy) {
			s = it->fr;
			if (it->sc.status != 0)
				cout << s << " INCONSISTENT\n";
			else
				cout << s << " " << ll(it->sc.cost) << endl;
		}
	}

	return 0;
}