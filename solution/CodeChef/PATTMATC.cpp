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


const int MAX_N = 1e5+5;
const int MAX_A = 555;
const int oo = 1e9;
const ll BASE = 1e4+7;


int n, nA;
string s, tmp, a[MAX_N];
ll h[MAX_N], g[MAX_N], p[MAX_N];
int len[MAX_N], f[MAX_N][MAX_A], ans[MAX_N];


ll getG(int i, int j) {
	return g[j]-g[i-1]*p[j-i+1];
}


int main() {
#ifdef DEBUG
	freopen("PATTMATC.in", "r", stdin);
	freopen("PATTMATC.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	p[0]=1;
	fori(i,1,MAX_N-1) p[i]=p[i-1]*BASE;

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> tmp;
		nA=0;
		for (int i=0, j=0, n=sz(tmp); i<n; i=j) {
			while (tmp[j]=='*') ++j;
			if (j>=n) break;
			s="";
			while (j<n && tmp[j]!='*') s.pb(tmp[j++]);
			a[++nA]=s;
		}
		fori(k,1,nA) {
			len[k]=sz(a[k]);
			h[k]=0;
			fori(i,1,len[k]) h[k]=h[k]*BASE + a[k][i-1];
		}

		cin >> s;
		n=sz(s);

		if (nA==0) {
			fori(i,1,n) cout << i << " ";
			cout << endl;
			continue;
		}

		g[0]=0;
		fori(i,1,n) g[i]=g[i-1]*BASE + s[i-1];
		fori(i,1,nA) f[n+1][i] = oo;
		ford(i,n,1) {
			fori(k,1,nA) {
				f[i][k]=f[i+1][k];
				int j=i+len[k]-1;
				if (j<=n && h[k]==getG(i, j))
					f[i][k]=i;
			}
			int p=i-1;
			fori(k,1,nA) {
				++p;
				p=f[p][k]+len[k]-1;
				if (p>n) break;
			}
			if (p>n) p=-1;
			ans[i]=p;
		}
		fori(i,1,n) cout << ans[i] << " ";
		cout << endl;
	}

	return 0;
}