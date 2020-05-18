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


const int MAX_N = 1e3+33;

string s;
int f[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100712D.in", "r", stdin);
	freopen("100712D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		int n, k;
		cin >> n >> k;
		cin >> s;
		f[0]=0;
		fori(i,1,n) {
			f[i] = 1e9;
			bool ok=true;
			ford(j,i,1) {
				if (i-j+1>k) break;
				if (s[j-1]==s[j]) ok=true;
				if (ok) f[i]=min(f[i],f[j-1]+(j>1));
				if (j==i) ok=false;
			}
		}
		cout << f[n] << endl;
	}

	return 0;
}