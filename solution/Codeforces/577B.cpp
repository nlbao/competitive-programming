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


const int MAX_N = 1e3+33;


int a[MAX_N], q[MAX_N];
bool ok[MAX_N];


int main() {
#ifdef DEBUG
	freopen("577B.in", "r", stdin);
	freopen("577B.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(a, 0);
	int n, m;
	cin >> n >> m;
	fori(i,1,n) {
		int x;
		cin >> x;
		++a[x%m];
	}

	filla(ok,0);
	int l=1, r=1;
	q[1]=0;
	fori(x,0,m-1) {
		if (ok[0]) break;
		if (!a[x]) continue;
		int l=1;
		fori(k,1,a[x]) {
			if (ok[0]) break;
			int rr=r, y;
			fori(i,l,rr) {
				y=(x+q[i])%m;
				if (ok[y]) continue;
				ok[y]=1;
				q[++r]=y;
			}
			l=rr+1;
			if (l>r) break;
		}
	}

	if (ok[0]) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}