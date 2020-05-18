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


const int ID[9][5] = {
	0, 1, 1, 1, 0,
	2, 0, 0, 0, 3,
	2, 0, 0, 0, 3,
	2, 0, 0, 0, 3,
	0, 4, 4, 4, 0,
	5, 0, 0, 0, 6,
	5, 0, 0, 0, 6,
	5, 0, 0, 0, 6,
	0, 7, 7, 7, 0
};


int main() {
#ifdef DEBUG
	freopen("100186K.in", "r", stdin);
	freopen("100186K.out", "w", stdout);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	int c[10];
	string a[10];
	filla(c, 0);
	fori(i,1,9) cin >> a[i];
	int l=1;
	fori(turn,1,10) {
		fori(i,1,9) {
			fori(j,l,l+4) {
				if (a[i][j-1]=='.') continue;
				int x=i-1, y=j-l;
				++c[ID[x][y]];
			}
		}
		l+=6;
	}
	fori(i,1,7) {
		c[i] /= 3;
		if (c[i]==0) cout << -1;
		else if (c[i]==10) cout << 1;
		else cout << 0;
		cout << " ";
	}

	return 0;
}