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

const int N = 13;
const int M = 4;
const string a[N] = {"2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"};
const string b[M] = {"D", "C", "H", "S"};

map<string, pii> id;
vector<pii> x, y;
bool ok[N+10][M+10];


int main() {
#ifdef DEBUG
	freopen("5065.in", "r", stdin);
	freopen("5065.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	fori(i,0,N-1) fori(j,0,M-1) id[a[i]+b[j]]=mp(i,j);

	int nTest=read();
	string s;
	while (nTest--) {
		filla(ok, 1);
		x.clear();
		y.clear();
		fori(turn,1,26) {
			cin >> s;
			int i=id[s].fr, j=id[s].sc;
			ok[i][j]=0;
			x.pb(mp(i, j));
		}
		fori(i,0,N-1) fori(j,0,M-1) if (ok[i][j]) y.pb(mp(i,j));
		sort(x.begin(), x.end());
		sort(y.begin(), y.end());
		int ans=0, i=25, j=25;
		while (i>=0 && j>=0) {
			if (!(x[i]>y[j])) {
				--j;
				continue;
			}
			++ans;
			--i;	--j;
		}
		cout << ans << endl;
	}

	return 0;
}