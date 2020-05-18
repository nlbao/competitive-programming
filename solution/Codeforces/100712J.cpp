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


const int MAX_N = 222;

int a[MAX_N], b[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100712J.in", "r", stdin);
	freopen("100712J.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		filla(a,0);
		filla(b,0);
		int n, m;
		cin >> n >> m;
		fori(i,1,n) ++a[read()];
		fori(i,1,m) ++b[read()];
		int j=1;
		fori(i,1,15) {
			if (a[i]==0) continue;
			while (j<=50 && b[j]<a[i]) ++j;
			if (j>50) break;
			b[j]-=a[i];
			a[i]=0;
			++j;
		}
		bool ans=true;
		fori(i,1,15) if (a[i]) ans=false;
		if (ans) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}