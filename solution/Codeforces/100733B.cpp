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


const int MAX_N = 111;
const int MAX_C = 266;


int n;
string a[MAX_N], b[MAX_N], s;
int c[MAX_N][MAX_C], d[MAX_C];


int main() {
#ifdef DEBUG
	freopen("100733B.in", "r", stdin);
	freopen("100733B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	filla(c, 0);
	fori(i,1,n) {
		cin >> a[i] >> b[i];
		foreach(it, a[i]) ++c[i][*it];
		foreach(it, b[i]) ++c[i][*it];
	}
	int maxI=1, maxF=0;
	fori(i,1,n) {
		int h, w;
		cin >> h >> w;
		filla(d, 0);
		fori(x,1,h) {
			cin >> s;
			foreach(it, s) ++d[*it];
		}
		int f=1e9;
		fori(x,0,MAX_C-1) if (c[i][x]) f=min(f, d[x]/c[i][x]);
		if (f>maxF) {
			maxF=f;
			maxI=i;
		}
	}
	cout << a[maxI] << " " << b[maxI] << endl;

	return 0;
}