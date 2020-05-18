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


const int MAX_N = 1111;


bool f[MAX_N];
pii pos[11];


bool isPre(int x, int y) {
	if (x==y) return 1;
	if (y==0) return (x%3!=0);
	if (x==0) return 0;
	return pos[x].fr<=pos[y].fr && pos[x].sc<=pos[y].sc;
}


bool check(int x) {
	stringstream ss;
	string s;
	ss << x;
	ss >> s;
	int n=sz(s);
	fori(i,0,n-2) if (!isPre(s[i]-'0', s[i+1]-'0')) return 0;
	return 1;
}


bool ok(int x) {
	if (x<0 || x>999) return 0;
	return f[x];
}


int main() {
#ifdef DEBUG
	freopen("6934.in", "r", stdin);
	freopen("6934.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int c=0;
	fori(i,1,3) fori(j,1,3) pos[++c]=mp(i, j);

	int n=999;
	filla(f, 0);
	f[0]=1;
	fori(i,1,n) f[i]=check(i);

	int nTest=read();
	fori(testid,1,nTest) {
		int k, ans;
		cin >> k;
		fori(d,0,n) {
			if (ok(k+d)) {
				ans=k+d;
				break;
			}
			if (ok(k-d)) {
				ans=k-d;
				break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}