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


const int MAX_N = 107;
const int oo = 1e9;


int n, m;
string s[MAX_N], t;
int len[MAX_N], a[MAX_N][MAX_N], b[MAX_N][MAX_N], f[MAX_N];
bool preS[MAX_N][MAX_N], preTS[MAX_N][MAX_N], preST[MAX_N][MAX_N];


inline bool isPrefix(const string &a, const string &b) {
	int n=sz(a);
	if (n>sz(b)) return 0;
	fori(i,0,n-1) if (a[i]!=b[i]) return 0;
	return 1;
}


int main() {
#ifdef DEBUG
	freopen("100484K.in", "r", stdin);
	freopen("100484K.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	fori(i,1,n) cin >> s[i];
	sort(s+1,s+1+n);
	fori(i,1,n) len[i]=sz(s[i]);
	cin >> t;
	m=sz(t);

	filla(preS, 0);
	filla(preST, 0);
	filla(preTS, 0);
	fori(i,1,n) fori(j,i+1,n) preS[i][j]=isPrefix(s[i], s[j]);
	fori(i,1,n) fori(j,0,m-1) {
		preST[i][j]=isPrefix(s[i], t.substr(0,j+1));
		preTS[j][i]=isPrefix(t.substr(0,j+1), s[i]);
	}

	ford(i,n,1) fori(j,0,m) a[i][j]=b[j][i]=oo;
	ford(i,n,1) fori(j,0,m-1) if (len[i]<=j+1) {
		if (preST[i][j]) {
			a[i][j]=min(1LL*a[i][j], j+1-len[i]);
			if (j>0) a[i][j]=min(a[i][j], a[i][j-1] + 1);
			fori(k,i+1,n) if (preS[i][k] && preST[k][j])
				a[i][j]=min(1LL*a[i][j], k-i + a[k][j]);
		}
	}
	fori(i,1,n) ford(j,m-1,0) if (len[i]>=j+1) {
		if (preTS[j][i]) {
			int c=1;
			fori(k,1,i-1) if (preTS[j][k]) ++c;
			b[j][i]=min(b[j][i], c);
			fori(k,j+1,m-1) b[j][i]=min(1LL*b[j][i], k-j + b[k][i]);
			fori(k,1,i-1) if (preTS[j][k] && preS[k][i])
				b[j][i]=min(1LL*b[j][i], b[j][k] + i-k);
		}
	}

	f[0]=1;
	fori(i,1,m-1) {
		f[i]=i+1;
		fori(k,1,n) f[i]=min(1LL*f[i], k + a[k][i]);
		fori(j,0,i-1) fori(k,1,n) f[i]=min(f[i], f[j] + b[j][k] + a[k][i]);
	}
	cout << f[m-1]+1 << endl;

	return 0;
}