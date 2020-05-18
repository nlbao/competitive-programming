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


const int MAX_H=25*60*60;
const int H3=10800;
const int M15=900;


inline int second(const string &a) {
	int n=sz(a), h=0, m=0, s=0, i=0;
	while (i<n && isdigit(a[i])) h=h*10+a[i++]-'0';	++i;
	while (i<n && isdigit(a[i])) m=m*10+a[i++]-'0';	++i;
	while (i<n && isdigit(a[i])) s=s*10+a[i++]-'0';	++i;
	return h*3600 + m+60 + s;
}


int main() {
#ifdef DEBUG
	freopen("100687J.in", "r", stdin);
	freopen("100687J.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int n=read();
	string s;
	fori(i,1,n) {
		cin >> s;
		int x=second(x);
		a[i]=mp(x,x+H3);
	}
	sort(a+1,a+1+n);

	int ans=0, f=0, k=-1, i=1;
	b.clear();	c.clear();
	while (i<=n || !b.empty()) {
		++k;
		if (i<=n) {
			k=max(k, a[i].fr);
			while (i<=n && a[i].fr<=k) {
				b.insert(mp(a[i].sc, a[i].fr));
				++i;
			}
		}
		while (!c.empty() && *c.begin()
		while (!b.empty() && *b.begin()-M15==k) {
			int x=*b.begin();
			b.erase(b.begin());
			int t=k;
			if (k)
		}
	}

	return 0;
}