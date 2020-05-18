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


int n, m;
pair<int,pii> a[MAX_N];
int p[MAX_N];

int getRoot(int u) {
	return p[u]<0 ? u : p[u]=getRoot(p[u]);
}


int main() {
#ifdef DEBUG
	freopen("100712F.in", "r", stdin);
	freopen("100712F.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> m;
		fori(i,0,m-1) {
			int x, y, c;
			cin >> x >> y >> c;
			a[i]=mp(c,mp(x,y));
		}
		sort(a,a+m);
		int c=n, ans=-1;
		filla(p,-1);
		fori(i,0,m-1) {
			int u=a[i].sc.fr, v=a[i].sc.sc;
			u=getRoot(u), v=getRoot(v);
			if (u==v) continue;
			p[u]=v;
			--c;
			if(c==1) {
				ans=a[i].fr;
				break;
			}
		}
		cout << ans << endl;
	}

	return 0;
}