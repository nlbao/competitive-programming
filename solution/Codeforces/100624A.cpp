#pragma comment(linker, "/STACK:1024000000")
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


const int MAX_N = 22;
const int MAX_F = (1<<(MAX_N-1))+44;


int n, a[MAX_N][MAX_N], id[MAX_N], c[MAX_N];
bool f[MAX_F], ok[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100624A.in", "r", stdin);
	freopen("100624A.out", "w", stdout);
#endif
	fori(i,1,MAX_N-1) id[i]=1<<(i-1);

	int nTest;
	scanf("%d", &nTest);
	fori(testid,1,nTest) {
		scanf("%d", &n);
		fori(i,1,n) fori(j,1,n) scanf("%d", &a[i][j]);
		filla(ok, 0);

		int nMask=(1<<n)-1;
		fori(x,0,nMask) f[x]=0;
		f[nMask]=1;
		ford(mask,nMask,1) if (f[mask]) {
			fori(i,1,n) c[i]=0;
			fori(i,1,n) if (mask&id[i]) {
				fori(j,1,n) c[j]-=a[j][i];
			}
			bool ck=1;
			fori(i,1,n) if ((mask&id[i]) && c[i]<0) {
				ck=0;
				f[mask-id[i]]=1;
			}
			if (ck && __builtin_popcount(mask)==1) {
				fori(i,1,n) if (mask&id[i]) ok[i]=1;
			}
		}

		bool ck=1;
		fori(i,1,n) if (ok[i]) {
			ck=0;
			printf("%d", i);
			if (i<n) printf(" ");
		}
		if (ck) printf("0");
		printf("\n");
		// if (testid<nTest) printf("\n");
	}

	return 0;
}