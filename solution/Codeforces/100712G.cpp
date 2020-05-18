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


const int MAX_N = 55;

int n, limit;
int a[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100712G.in", "r", stdin);
	freopen("100712G.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		cin >> n >> limit;
		fori(i,0,n-1) cin >> a[i];
		int ans=0;
		fori(mask,0,(1<<n)-1) {
			int sum=0, c=0;
			fori(i,0,n-1)
				if (mask&(1<<i)) {
					sum += a[i];
					++c;
				}
			if (sum<limit) continue;
			bool ck=true;
			fori(i,0,n-1) {
				if (mask&(1<<i) && sum-a[i]>=limit) {
					ck=false;
					break;
				}
			}
			if (ck) ans=max(ans,c);
		}
		cout << ans << endl;
	}

	return 0;
}