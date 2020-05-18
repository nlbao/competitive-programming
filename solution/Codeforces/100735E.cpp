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


ll a[MAX_N][MAX_N], r[MAX_N];


int main() {
#ifdef DEBUG
	freopen("100735E.in", "r", stdin);
	freopen("100735E.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	ll n, s=0;
	cin >> n;
	fori(i,1,n) {
		r[i]=0;
		fori(j,1,n) {
			cin >> a[i][j];
			r[i]+=a[i][j];
		}
		s+=r[i];
	}
	if (n==1) {
		cout << a[1][1];
		return 0;
	}
	ll x=s/(n-1);
	fori(i,1,n) {
		fori(j,1,n) {
			if (i==j) a[i][j]=x-r[i];
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}