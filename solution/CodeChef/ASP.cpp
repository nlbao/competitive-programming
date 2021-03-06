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


const int MAX_N = 1e6+6;

int n;
int a[MAX_N];
bool ok[MAX_N];


int main() {
#ifdef DEBUG
	freopen("ASP.in", "r", stdin);
	freopen("ASP.out", "w", stdout);
#endif
	int nTest;
	scanf("%d", &nTest);
	while (nTest--) {
		scanf("%d", &n);
		fori(i,1,n) {
			scanf("%d", &a[i]);
			ok[i]=1;
		}
		fori(i,1,n-1) if (ok[i] && a[i]>a[i+1]) {
			swap(a[i], a[i+1]);
			ok[i+1]=0;
		}
		bool ck=1;
		fori(i,1,n-1) if (a[i]>a[i+1]) {
			ck=0;
			break;
		}
		if (ck) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}