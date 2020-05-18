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
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 17;
const int n = 6;


int sum, a[MAX_N];
ll f[MAX_N][MAX_N];


void solve_1() {
	fori(i,1,n) cin >> a[i];
	ll ans=0, s=sum;
	fori(i,1,n) {
		fori(x,0,a[i]-1) ans+=f[i+1][s-x];
		s-=a[i];
	}
	cout << ans;
}


void solve_2() {
	ll val, s=sum;
	cin >> val;
	++val;
	filla(a, 0);
	fori(i,1,n) {
		fori(x,0,s) {
			if (f[i+1][s-x]<val) val-=f[i+1][s-x];
			else {
				a[i]=x;
				s-=x;
				break;
			}
		}
	}
	if (s>0) a[n]=s;
	fori(i,1,n) cout << a[i] << " ";
}


int main() {
#ifdef DEBUG
	freopen("100642D.in", "r", stdin);
	freopen("100642D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	sum=15;
	filla(f, 0);
	fori(i,0,sum) f[n][i]=1;
	ford(i,n-1,1) {
		f[i][0]=1;
		fori(x,1,sum) fori(y,0,x) f[i][x]+=f[i+1][x-y];
	}

	int testid=0;
	while (1) {
		char ch;
		cin >> ch;
		if (ch=='e') break;
		cout << "Case " << ++testid << ": ";
		if (ch=='m') solve_1();
		else solve_2();
		cout << endl;
	}

	return 0;
}