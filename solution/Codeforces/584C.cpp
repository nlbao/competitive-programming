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


int n, t;
string s[2], ans;


inline char ch(int x) {
	return char('a'+x);
}

inline char find(char x, char y) {
	fori(i,0,25) if (ch(i)!=x && ch(i)!=y) return ch(i);
	return '-';
}


bool solve() {
	int d=0;
	fori(i,0,n-1) if (s[0][i]!=s[1][i]) ++d;
	int e=n-d;
	fori(x3,0,d+e) {
		int x1=t-x3, x2=t-x3;
		int xd=d-(x1+x2), xe=x3-xd;
		if (x1<0 || xd<0 || xe>e || xd>x3 || xe>x3) continue;
		fori(i,0,n-1) if (s[0][i]!=s[1][i]) {
			if (x1) {
				ans[i]=s[1][i];
				--x1;
			}
			else if (x2) {
				ans[i]=s[0][i];
				--x2;
			}
			else if (xd) {
				ans[i]=find(s[0][i], s[1][i]);
				--xd;
			}
		}
		fori(i,0,n-1) if (s[0][i]==s[1][i] && xe) {
			ans[i]=find(s[0][i], s[1][i]);
			--xe;
		}
		return 1;
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("584C.in", "r", stdin);
	freopen("584C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> t;
	cin >> s[0] >> s[1];
	ans=s[0];
	if (solve()) cout << ans << endl;
	else cout << -1 << endl;

	return 0;
}