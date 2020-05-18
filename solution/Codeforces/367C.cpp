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

const int MAX_N = 2*1000006;
const int MAX_M = 100005;


ll f[MAX_N];
int a[MAX_M];


int main() {
#ifdef DEBUG
	freopen("367C.in", "r", stdin);
	freopen("367C.out", "w", stdout);
#endif
	// f[i] is the least edges needed, that the graph is an semi-Eulerian
	f[1] = 1;
	for (ll i = 2; i < MAX_N; ++i) {
		f[i] = i*(i-1)/2;
		if (i&1) ++f[i];
		else f[i] += i/2;
	}

	int n = read(), m = read();
	rep(i, m) {
		read();
		read(a[i]);
	}
	sort(a, a+m);
	reverse(a, a+m);

	ll res = 0;
	int c = 0;
	while (c < m && f[c+1] <= n) ++c;
	rep(i, c) res += ll(a[i]);
	cout << res << endl;
	return 0;
}