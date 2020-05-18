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


const int MAX_N = 1e5+5;


ll f[MAX_N];


bool isPalin(int x) {
	stringstream ss;
	ss << x;
	string s;
	ss >> s;
	int n=s.size();
	for (int i=0,j=n-1; i<j; ++i, --j)
		if (s[i]!=s[j]) return 0;
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("SPALNUM.in", "r", stdin);
	freopen("SPALNUM.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	f[0]=0;
	fori(i,1,MAX_N-1) f[i]=f[i-1]+(isPalin(i)?i:0);

	int nTest=read();
	fori(testid,1,nTest) {
		int l, r;
		cin >> l >> r;
		cout << f[r]-f[l-1] << endl;
	}

	return 0;
}