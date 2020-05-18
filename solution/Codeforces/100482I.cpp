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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 111;


int n, nQ;
string a[MAX_N];
int len[MAX_N];


bool solve(const string &s) {
	int m=sz(s);
	fori(i,1,n) if (a[i]==s) return 1;
	int c=0;
	fori(i,1,n) if (len[i]==m) {
		int d=0;
		fori(k,0,m-1) if (a[i][k]!=s[k]) ++d;
		if (d==1) ++c;
	}
	return c==1;
}


int main() {
#ifdef DEBUG
	freopen("100482I.in", "r", stdin);
	freopen("100482I.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	string s;
	fori(testid,1,nTest) {
		cout << "Case #" << testid << ":\n";
		cin >> n >> nQ;
		fori(i,1,n) {
			cin >> a[i];
			len[i]=sz(a[i]);
		}
		while (nQ--) {
			cin >> s;
			if (solve(s)) cout << "yes\n";
			else cout << "no\n";
		}
	}

	return 0;
}