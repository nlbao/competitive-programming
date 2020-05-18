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
const int MAX_W = 515;
const int oo = 1e9+7;


int n, H, W, maxH;
int p[MAX_N], h[MAX_N], f[MAX_N][MAX_W];
pii a[MAX_N];


int solve() {
	if (maxH <= H) return 0;
	int ans=oo;
	fori(pos,1,n-1) {
		if (h[pos] > H) continue;
		int l = (pos==1) ? 1 : p[pos-1]+1;
		fori(i,1,n) fori(x,0,MAX_W-1) f[i][x]=oo;
		fori(x,l,MAX_W-1) f[pos][x]=abs(p[pos]-x) * h[pos];
		if (h[pos+1]==maxH) {
			if (h[pos+1]-h[pos] > H) continue;
			fori(x,l,p[pos+1]-1)
				if (abs(p[pos+1]-x) <= W) {
					ans=min(ans, f[pos][x]);
					// cout << "pos: " << pos << " " << x << ": " << f[pos][x] << endl;
				}
			continue;
		}
		fori(i,pos+1,n-1) {
			if (h[i]-h[i-1] > H) break;
			fori(x,l+i-pos,MAX_W-1) {
				int t=abs(p[i]-x) * h[i];
				int ly=max(1LL, x-W), ry=x-1;
				fori(y,ly,ry)
					f[i][x]=min(f[i][x], f[i-1][y] + t);
			}
			if (h[i+1]==maxH) {
				if (h[i+1]-h[i] > H) break;
				fori(x,1,p[i+1]-1)
					if (abs(p[i+1]-x) <= W) {
						ans=min(ans, f[i][x]);
						// cout << pos << " --> " << i << ": " << x << ": " << p[i] << " " << h[i] << " " << f[i][x] << endl;
					}
				break;
			}
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("6042.in", "r", stdin);
	freopen("6042.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> H >> W;
		fori(i,1,n) cin >> a[i].fr >> a[i].sc;
		sort(a+1,a+1+n);
		maxH=0;
		fori(i,1,n) {
			p[i]=a[i].fr;	h[i]=a[i].sc;
			maxH=max(maxH, h[i]);
		}
		int ans=solve();
		fori(i,1,n) p[i]=MAX_W-1-p[i];
		for (int i=1, j=n; i<j; ++i, --j) {
			swap(p[i], p[j]);
			swap(h[i], h[j]);
		}
		ans=min(ans, solve());
		if (ans>=oo) ans=-1;
		cout << "Case #" << testid << ": " << ans << endl;
	}

	return 0;
}