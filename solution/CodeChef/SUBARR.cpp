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

const int MAX_N = int(1e6)+6;

int n;
ll k;
pair<ll, int> f[MAX_N];
int c[MAX_N];



ll get(int x) {
	// if (x == 0) return c[x];
	if (x < 1 || x > n) return 0;
	return c[x] + get(x - (x & (-x)));
}



void update(int x) {
	// if (x == 0) {
	// 	++c[x];
	// 	update(1);
	// }
	if (x < 1 || x > n) return;
	++c[x];
	update(x + (x & (-x)));
}



int main() {
#ifdef DEBUG
	freopen("SUBARR.in", "r", stdin);
	freopen("SUBARR.out", "w", stdout);
#endif
	cin >> n >> k;
	f[0] = mp(0, 1);
	ll s = 0;
	foru(i, 1, n) {
		ll a = read();
		s += a;
		f[i] = mp(s-k*ll(i), i+1);
	}
	// foru(i, 0, n) cout << f[i].fr << " " << f[i].sc << endl;
	sort(f, f+n+1);

	// cout << endl;
	// foru(i, 0, n) cout << f[i].fr << " " << f[i].sc << endl;

	ll res = 0;
	fill(c, 0);
	rep(i, n+1) {
		int x = f[i].sc;
		res += get(x-1);
		update(x);
	}
	cout << res << endl;
	return 0;
}