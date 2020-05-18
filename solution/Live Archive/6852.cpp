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


const int MAX_N = 1e5+5;
const int MAX_A = 18;


int n, m;
int c[MAX_A][MAX_A];
int ans[MAX_N];


int main() {
#ifdef DEBUG
	freopen("6852.in", "r", stdin);
	freopen("6852.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> m;
		filla(c, 0);
		fori(i,1,n) {
			int a, b;
			cin >> a >> b;
			++c[b][a-1];
		}
		fori(i,1,MAX_A-1)
			ford(j,i-1,0) c[i][j] += c[i][j+1];
		filla(ans, 0);
		fori(pos,0,m-1) {
			int s=0;
			fori(i,1,16) s += c[i][pos%i];
			++ans[s];
		}
		fori(i,0,n) cout << ans[i] << endl;
	}

	return 0;
}