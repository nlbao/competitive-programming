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


const int MAX_N = 55;


int n;
string a[MAX_N];


bool check(const string &s) {
	int m=sz(s);
	fori(i,2,n) {
		bool ok=0;
		int l=sz(a[i]);
		fori(k,0,l-m) if (a[i].substr(k,m)==s) {
			ok=1;
			break;
		}
		if (!ok) return 0;
	}
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("STEM.in", "r", stdin);
	freopen("STEM.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n;
		fori(i,1,n) cin >> a[i];
		string ans="";
		int m=sz(a[1]);
		fori(i,0,m-1) fori(j,i,m-1) {
			string s=a[1].substr(i,j-i+1);
			if (check(s)) {
				if (sz(s)>sz(ans) || (sz(s)==sz(ans) && s<ans))
					ans=s;
			}
		}
		cout << ans << endl;
	}

	return 0;
}