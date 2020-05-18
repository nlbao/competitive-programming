#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for(int i=(a); i<=(b); ++i)
#define ford(i,a,b) for(int i=(a); i>=(b); --i)
#define forix(i,a,b,x) for(int i=(a); i<=(b); i+=(x))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 16;
const int MAX_F = 1<<MAX_N;


int n, nMask, crrMask;
ll L, sum, w[MAX_N][MAX_N], f[MAX_F][MAX_N];
bool found;
set<ll> visted[MAX_F][MAX_N];


bool tryf(int u) {
	if (crrMask==nMask) {
		if (sum+w[u][1]==L) {
			found=1;
			return 1;
		}
		return 0;
	}
	if (sum>L) return 0;
	if (sum+w[u][1]>L) return 0;
	if (visted[crrMask][u].find(sum) != visted[crrMask][u].end())
		return 0;
	visted[crrMask][u].insert(sum);

	int x=nMask-crrMask;
	x |= 1;
	fori(i,2,n) if (x&(1<<(i-1))) {
		ll tmp = w[u][i];
		if (sum+tmp+f[x][1] < L) continue;
		sum += tmp;
		crrMask |= 1<<(i-1);
		if (tryf(i)) return 1;
		crrMask -= 1<<(i-1);
		sum -= tmp;
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("6958.in", "r", stdin);
	// freopen("test.in", "r", stdin);
	freopen("6958.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	while (cin >> n >> L) {
		fori(i,1,n) fori(j,1,n) cin >> w[i][j];
		nMask=(1<<n)-1;
		fori(x,0,nMask) fori(i,1,n) {
			f[x][i]=-1;
			visted[x][i].clear();
		}
		fori(i,1,n) f[1<<(i-1)][i]=0;
		fori(mask,1,nMask) fori(i,1,n) if (f[mask][i]>=0) {
			fori(j,1,n) {
				int x=mask|(1<<(j-1));
				if (x==mask) continue;
				f[x][j]=max(f[x][j], f[mask][i]+w[i][j]);
			}
		}
		found=0;
		sum=0;
		crrMask=1;
		tryf(1);
		if (found) cout << "possible\n";
		else cout << "impossible\n";
	}

	return 0;
}