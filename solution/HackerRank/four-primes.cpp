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


const int MAX_N = 8088;
const int oo = 1e9;


int nP;
int f[MAX_N], p[MAX_N];
bool prime[MAX_N];


bool solve(int n) {
	fori(i,1,nP) {
		if (p[i]>n) break;
		fori(j,i,nP) {
			if (p[j]>n) break;
			fori(k,j,nP) {
				if (p[k]>n) break;
				fori(t,k,nP) {
					if (p[t]>n) break;
					if ((p[i]|p[j]|p[k]|p[t]) == n)
						return 1;
				}
			}
		}
	}
	return 0;
}


int main() {
#ifdef DEBUG
	freopen("four-primes.in", "r", stdin);
	freopen("four-primes.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	fori(i,1,MAX_N-1) f[i]=oo;
	filla(prime, 1);
	prime[1]=0;
	nP=0;
	fori(i,2,MAX_N-1) if (prime[i]) {
		p[++nP]=i;
		f[i]=1;
		for (ll j=i*i; j<MAX_N; j+=i)
			prime[j]=0;
		fori(x,1,MAX_N-1) {
			int y=i|x;
			if (y<MAX_N)
				f[y]=min(f[y], f[x]+1);
		}
	}

	// fori(i,1,10) {
	// 	bool ck=solve(i);
	// 	if (f[i]<=4 && !ck) {
	// 		cout << "1 " << i << " " << f[i] << endl;
	// 		return 0;
	// 	}
	// 	if (f[i]>4 && ck) {
	// 		cout << "2 " << i << " " << f[i] << endl;
	// 		return 0;
	// 	}
	// }
	// return 0;

	int nTest=read();
	fori(testid,1,nTest) {
		int n;
		cin >> n;
		if (f[n]<=4) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}