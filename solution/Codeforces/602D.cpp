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
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 1e5+55;

int n, nQ;
int a[MAX_N], d[MAX_N], stk[MAX_N];
ll f[MAX_N];


ll solve(int n) {
	int top=0;
	ll ans=0, s=0;
	fori(i,1,n) {
		ll x=a[i];
		while (top>0 && a[stk[top]]<=x) {
			s -= f[top];
			--top;
		}
		stk[++top]=i;
		f[top]=(top==1) ? i*x : (i-stk[top-1])*x;
		s += f[top];
		ans += s;
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("602D.in", "r", stdin);
	freopen("602D.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n >> nQ;
	fori(i,1,n) cin >> a[i];
	fori(i,1,n-1) d[i]=abs(a[i+1]-a[i]);
	fori(qid,1,nQ) {
		int l, r;
		cin >> l >> r;
		fori(i,l,r-1) a[i-l+1]=d[i];
		cout << solve(r-l) << endl;
	}

	return 0;
}