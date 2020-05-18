#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define sz(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

ll n, d;
ll h[11115];


bool cal(ll x, ll gg, ll i, ll &f, ll &g) {
	ll k = (gg-x)/d, r = (gg-x)%d;
	if (r != 0 || k < 0) return false;
	f += k;
	g = x + (i-1)*k*d;
	return true;
}


ll solve() {
	ll f = 0, g = h[1];
	foru(i, 2, n) {
		ll x = h[i] + d*f;
		if (x < g) {
			if (!cal(x, g, i, f, g))
				return -1;
		}
		else if (x > g) {
			ll k = (x-g)/d, r = (x-g)%d;
			if (k < 0) return -1;
			f += k;
			g += k*d;
			if (r != 0) {
				g += d;
				if (!cal(x, g, i, f, g))
					return -1;
			}
		}
		// cout << f << " " << g << endl;
	}
	return f;
}


int main() {
#ifdef DEBUG
	freopen("C11PINES.in", "r", stdin);
	freopen("C11PINES.out", "w", stdout);
#endif
	n = read();
	d = read();
	foru(i, 1, n) h[i] = read();
	sort(h+1, h+1+n);
	cout << solve() << endl;
	return 0;
}