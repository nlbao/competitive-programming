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


const int MAX_N = 5e4+44;
const ll BASE = 1e4+7;


string s;
ll p[MAX_N], h[MAX_N];


inline ll getH(int i, int j) {
	return i==0 ? h[j] : h[j]-h[i-1]*p[j-i+1];
}


int solve() {
	int n = sz(s), ans=0;
	h[0]=s[0];
	fori(i,1,n-1) h[i]=h[i-1]*BASE + s[i];
	int ii=0, jj=n-1;
	for (int i=0, j=n-1; i<j; ++i, --j) {
		if (getH(ii,i)==getH(j,jj)) {
			ans += 2;
			ii=i+1, jj=j-1;
		}
	}
	if (ii<=jj) ++ans;
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("6439.in", "r", stdin);
	freopen("6439.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	p[0]=1;
	fori(i,1,MAX_N-1) p[i]=p[i-1]*BASE;

	int nTest = read();
	fori(testid,1,nTest) {
		cin >> s;
		cout << "Case #" << testid << ": " << solve() << endl;
	}

	return 0;
}