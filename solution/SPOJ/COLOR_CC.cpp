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


const int MAX_N = 14;
const int MAX_C = 1e5+5;
const int MAX_COLOR = 222;
const int MAX_P = 1<<MAX_N;


int n, nColor, color[MAX_COLOR], pos[MAX_C];
bool e[MAX_N][MAX_N], ec[MAX_N][MAX_COLOR], okMask[MAX_P], okMaskColor[MAX_P][MAX_COLOR];
ll f[MAX_COLOR][MAX_P];
vector<int> c[MAX_N];
set<int> id;
string s;


int main() {
#ifdef DEBUG
	freopen("COLOR_CC.in", "r", stdin);
	freopen("COLOR_CC.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	while (nTest--) {
		cin >> n;
		fori(i,0,n-1) {
			cin >> s;
			fori(j,0,n-1)
				e[i][j]=(s[j]=='Y');
		}

		id.clear();
		filla(ec, 0);
		fori(i,0,n-1) {
			c[i].clear();
			int len;
			cin >> len;
			fori(k,1,len) {
				int x;
				cin >> x;
				c[i].pb(x);
				id.insert(x);
			}
		}
		nColor=0;
		foreach(it, id) {
			color[++nColor] = *it;
			pos[*it]=nColor;
		}
		fori(i,0,n-1) foreach(it, c[i]) ec[i][pos[*it]] = nColor;

		int nMask=(1<<n)-1;
		filla(okMask, 0);
		filla(okMaskColor, 0);
		fori(mask,0,nMask) {
			okMask[mask]=1;
			fori(i,0,n-1) if (mask&(1<<i)) {
				fori(j,0,n-1)  if ((mask&(1<<j)) && e[i][j]) {
					okMask[mask]=0;
					break;
				}
				if (!okMask[mask]) break;
			}
			if (!okMask[mask]) continue;
			fori(c,1,nColor) {
				okMaskColor[mask][c]=1;
				fori(i,0,n-1) if ((mask&(1<<i)) && !ec[i][c]) {
					okMaskColor[mask][c]=0;
					break;
				}
			}
		}

		filla(f, 0);
		f[0][nMask]=1;
		fori(k,0,nColor-1) fori(mask,0,nMask) if (f[k][mask]) {
			int x=0;
			do {
				if (okMask[x] && okMaskColor[x][k+1]) {
					int y = mask - x;
					f[k+1][y] += f[k][mask];
				}
				x = (x+1+(~mask))&mask;
			} while (x!=0);
		}
		cout << f[nColor][0] << endl;
	}

	return 0;
}