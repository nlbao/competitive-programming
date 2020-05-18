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


const int MAX_N = 44;


ll p[MAX_N];


ll input() {
	int n;
	ll b, ans=0;
	cin >> n >> b;
	p[0]=1;
	fori(i,1,MAX_N-1) p[i]=p[i-1]*b;
	fori(i,1,n) {
		ll x;
		cin >> x;
		ans += x*p[n-i];
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("602A.in", "r", stdin);
	freopen("602A.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	ll a = input();
	ll b = input();
	if (a<b) cout << "<";
	else if (a>b) cout << ">";
	else cout << "=";

	return 0;
}