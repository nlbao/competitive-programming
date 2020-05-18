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
#define mt make_tuple
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N=19;
const int MAX_F=1<<MAX_N;


string s;
int n, m, w[MAX_N], a[MAX_N], f[MAX_F], p[MAX_N];
unordered_map<string, int> id;


int main() {
#ifdef DEBUG
	freopen("100676G.in", "r", stdin);
	freopen("100676G.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	fori(i,1,MAX_N-1) p[i]=1<<(i-1);

	int nTest=read();
	string x, y;
	fori(testid,1,nTest) {
		cin >> n >> m;
		id.clear();
		getline(cin, s);
		fori(pos,1,n) {
			getline(cin, s);
			int n=sz(s), i=n-1;
			while (i>=0 && isdigit(s[i])) --i;
			w[pos]=0;
			fori(k,i+1,n-1) w[pos]=w[pos]*10+s[k]-'0';
			id[s.substr(0,i)]=pos;
			a[pos]=0;
		}
		fori(turn,1,m) {
			getline(cin, s);
			int n=sz(s), i=0;
			while (i<n && s[i]!='-') ++i;
			x=s.substr(0, i-1);
			while (i<n && (s[i]=='-' || s[i]=='>')) ++i;
			++i;
			y=s.substr(i, n-i);
			a[id[y]] |= p[id[x]];
		}

		int nMask=(1<<n)-1;
		fori(i,0,nMask) f[i]=-1;
		f[0]=0;
		fori(mask,0,nMask) if (f[mask]>=0) {
			int c=__builtin_popcount(mask)+1;
			fori(i,1,n) if (!(mask&p[i])) {
				if ((mask&a[i])!=a[i]) continue;
				int x=mask|p[i];
				f[x]=max(f[x], f[mask]+c*w[i]);
			}
		}
		cout << f[nMask] << endl;
	}

	return 0;
}