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
#define pb push_back
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int oo = 1e9;

int n, k;
set<int> q;


int main() {
#ifdef DEBUG
	freopen("100712K.in", "r", stdin);
	freopen("100712K.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> k;
		pii ans(oo, oo);
		q.clear();
		fori(i,1,n) {
			int x;
			cin >> x;
			if (i>1 && x>0) {
				if (k%x==0) {
					int y=k/x;
					if (q.find(y)!=q.end()) {
						if (x>y) swap(x, y);
						pii t(x, y);
						ans=min(ans, t);
					}
				}
			}
			q.insert(x);
		}
		if (ans.fr>=oo) cout << -1 << endl;
		else cout << ans.fr << " " << ans.sc << endl;
	}

	return 0;
}