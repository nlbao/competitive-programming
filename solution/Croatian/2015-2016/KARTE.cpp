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


string s;
int c[4];
set<pii> q;


int num(char x) {
	if (x=='P') return 0;
	if (x=='K') return 1;
	if (x=='H') return 2;
	return 3;
}


int main() {
#ifdef DEBUG
	freopen("KARTE.in", "r", stdin);
	freopen("KARTE.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> s;
	int n = sz(s);
	fori(i,0,3) c[i]=13;
	for (int i = 0, j; i < n; i = j) {
		j = i+1;
		int x=num(s[i]), y=0;
		while (j<n && isdigit(s[j]))
			y=y*10 + s[j++]-'0';
		pii u(x, y);
		if (has(q, u)) {
			cout << "GRESKA\n";
			return 0;
		}
		q.insert(u);
		--c[x];
	}
	fori(i,0,3) cout << c[i] << " ";

	return 0;
}