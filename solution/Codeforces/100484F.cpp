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


const int MAX_N = 1e6+15;


string a[MAX_N], s;
int len[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100484F.in", "r", stdin);
	freopen("100484F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n=0;
	while (cin >> s) {
		if (sz(s)>0) a[++n]=s;
	}
	// sort(a+1,a+1+n);
	fori(i,1,n) len[i]=sz(a[i]);

	cout << a[1] << endl;
	int c=0;
	fori(i,2,n) {
		int l=min(len[i-1], len[i]);
		if (c>0 && a[i][c-1]!=a[i-1][c-1]) {
			while (c>0 && a[i][c-1]!=a[i-1][c-1]) --c;
		}
		else if (c<l && a[i][c]==a[i-1][c]) ++c;
		fori(k,1,c) cout << " ";
		cout << a[i] << endl;
	}

	return 0;
}