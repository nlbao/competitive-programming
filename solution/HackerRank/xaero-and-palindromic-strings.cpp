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


const int MAX_X = 26;
const int MAX_F = (1<<MAX_X)+4;

string s;
int f[MAX_F];


int main() {
#ifdef DEBUG
	freopen("xaero-and-palindromic-strings.in", "r", stdin);
	freopen("xaero-and-palindromic-strings.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int nTest=read();
	fori(testid,1,nTest) {
		ll a=0, b=0;
		cin >> s;
		int n=sz(s), mask=0;
		fori(i,0,n-1) {
			mask ^= 1<<(s[i]-'a');
			f[mask]=0;
			fori(x,0,25) f[mask^(1<<x)]=0;
		}
		f[0]=1;

		mask=0;
		fori(i,0,n-1) {
			b+=i+1;
			int x=s[i]-'a';
			mask ^= (1<<x);
			a += f[mask];
			fori(x,0,25) a += f[mask^(1<<x)];
			++f[mask];
		}

		ll d=__gcd(a, b);
		a/=d, b/=d;
		cout << a << "/" << b << endl;
	}

	return 0;
}