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


const int MAX_N = 33;


int n, m;
string a[MAX_N], s;


bool check(int x, int y) {
	int len=sz(s);
	fori(i,0,len-1) {
		char k=s[i];
		if (k=='<') --y;
		else if (k=='>') ++y;
		else if (k=='v') ++x;
		else --x;
	}
	return x>=0 && x<n && y>=0 && y<m && a[x][y]=='E';
}


int main() {
#ifdef DEBUG
	freopen("100687K.in", "r", stdin);
	freopen("100687K.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	n=16, m=32;
	fori(i,0,n-1) cin >> a[i];
	cin >> s;
	fori(i,0,n-1) fori(j,0,m-1) if (a[i][j]==':') {
		if (check(i, j)) cout << "Yes\n";
		else cout << "No\n";
		return 0;
	}

	return 0;
}