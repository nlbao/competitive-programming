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


string s;


int main() {
#ifdef DEBUG
	freopen("100733C.in", "r", stdin);
	freopen("100733C.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> s;
	int n=sz(s), i=0;
	ll a=0;
	while (i<n && isdigit(s[i])) a = a*10 + s[i++]-'0';
	ll ans=1;
	if (i<n-1) {
		++i;
		int j=n-1;
		while (isdigit(s[j]) && s[j]=='0') --j;
		fori(k,i,j) ans *= 10LL;
		while (i<=j && isdigit(s[i])) a = a*10 + s[i++]-'0';
	}
	ll d=__gcd(a, 100LL);
	ll g=a/d*100LL;
	ans *= g/a;
	cout << ans << endl;

	return 0;
}