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


const int MAX_X = 44;

int n, c[4][MAX_X], d[MAX_X][MAX_X], e[MAX_X][MAX_X];
string s[4];

#define num(x) (x-'A')


bool solve() {
	filla(c, 0);
	fori(i,0,3) fori(j,0,n-1) ++c[i][num(s[i][j])];
	fori(i,0,1) {
		int j=i+2;
		fori(x,0,MAX_X-1) if (c[i][x]!=c[j][x]) {
			// cout << i << " " << j << ": " << x << " " << c[i][x] << " " << c[j][x] << endl;
			return 0;
		}
	}

	filla(d, 0);
	filla(e, 0);
	fori(i,0,n-1) {
		++d[num(s[0][i])][num(s[1][i])];
		++e[num(s[2][i])][num(s[3][i])];
	}
	fori(x,0,MAX_X-1) fori(y,0,MAX_X-1) if (d[x][y]!=e[x][y]) {
		// cout << x << " " << y <<": " << d[x][y] << " " << e[x][y] << endl;
		return 0;
	}

	// fori(i,0,n-1) {
	// 	bool ck=0;
	// 	fori(j,0,n-1) if (i!=j) {
	// 		if (s[0][i]==s[2][j] && s[1][i]==s[3][j]) {
	// 			ck=1;
	// 			break;
	// 		}
	// 	}
	// 	if (!ck) return 0;
	// }
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("100623E.in", "r", stdin);
	freopen("100623E.out", "w", stdout);
#else
	freopen("enchanted.in", "r", stdin);
	freopen("enchanted.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	fori(i,0,3) cin >> s[i];
	reverse(s[1].begin(), s[1].end());
	reverse(s[3].begin(), s[3].end());

	// fori(i,0,3) cout << s[i] << endl;

	n=sz(s[0]);
	if (solve()) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}