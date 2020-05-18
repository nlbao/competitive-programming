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


string a, b;


int second(const string &a) {
	int n=sz(a), i=0, h=0, m=0, s=0;
	while (i<n && isdigit(a[i])) h = h*10+a[i++]-'0';	++i;
	while (i<n && isdigit(a[i])) m = m*10+a[i++]-'0';	++i;
	while (i<n && isdigit(a[i])) s = s*10+a[i++]-'0';	++i;
	return h*3600+m*60+s;
}


int main() {
#ifdef DEBUG
	freopen("100687I.in", "r", stdin);
	freopen("100687I.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n=read();
	bool ok=1;
	fori(i,1,n) {
		cin >> a >> b;
		if (second(b)-second(a)+1 > 10800)
			ok=0;
	}
	if (ok) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}