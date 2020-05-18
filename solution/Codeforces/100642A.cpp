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


const int MAX_N = 12;
const int MAX_F = (1<<MAX_N)+4;


int n;
pii a[MAX_N][3];
int f[MAX_F][MAX_N][3];


inline bool ok(int i, int x, int j, int y) {
	if (a[i][x].fr>=a[j][y].fr && a[i][x].sc>=a[j][y].sc) return 1;
	if (a[i][x].fr>=a[j][y].sc && a[i][x].sc>=a[j][y].fr) return 1;
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("100642A.in", "r", stdin);
	freopen("100642A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int testid=0;
	while (1) {
		cin >> n;
		if (n==0) break;
		fori(i,1,n) {
			int tmp[3];
			fori(x,0,2) cin >> tmp[x];
			a[i][0]=mp(tmp[0], tmp[1]);
			a[i][1]=mp(tmp[1], tmp[2]);
			a[i][2]=mp(tmp[2], tmp[0]);
		}
		int nMask=(1<<n)-1, ans=0;
		filla(f,0);
		fori(i,1,n) fori(x,0,2) f[1<<(i-1)][i][x]=1;
		fori(mask,0,nMask) fori(i,1,n) fori(x,0,2) if (f[mask][i][x]) {
			ans=max(ans, f[mask][i][x]);
			fori(j,1,n) if (!(mask&(1<<(j-1)))) fori(y,0,2) {
				if (!ok(i,x,j,y)) continue;
				int t=mask|(1<<(j-1));
				f[t][j][y]=max(f[t][j][y], f[mask][i][x]+1);
			}
		}
		cout << "Case " << ++testid << ": " << ans << endl;
	}

	return 0;
}