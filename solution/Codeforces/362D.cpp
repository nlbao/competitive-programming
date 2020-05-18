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
typedef pair<ll, int> plli;

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

const int MAX_N = 100005;

int n, m, p, q;
int f[MAX_N];
ll s[MAX_N];
priority_queue<plli, vector<plli>, greater<plli> > hmin;


int get_root(int u) {
	if (f[u] == u) return u;
	return f[u] = get_root(f[u]);
}



int main() {
#ifndef ONLINE_JUDGE
	freopen("362D.in", "r", stdin);
	freopen("362D.out", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &m, &p, &q);
	int c = n;
	fill(s, 0);
	foru(i, 1, n) f[i] = i;
	rep(i, m) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		x = get_root(x);
		y = get_root(y);
		if (x != y) {
			f[y] = x;
			s[x] += s[y] + ll(w);
			--c;
		}
		else s[x] += w;
	}

	if (c < q || c-q > p || (c == n && q == n && p > 0)) {
		printf("NO");
		return 0;
	}


	int tmp_u = -1, tmp_v = -1, tmp_p = 0;
	foru(i, 1, n)
		if (i == f[i]) hmin.push(mp(s[i], i));
		else tmp_u = i;
	if (tmp_u > 0 && c-q < p) {
		tmp_v = f[tmp_u];
		tmp_p = p - (c-q);
		p = c-q;
	}

	printf("YES\n");
	if (c == q && tmp_p > 0) {
		rep(i, tmp_p)
			printf("%d %d\n", tmp_u, tmp_v);
		return 0;
	}

	// cout << p << "    " << hmin.size() << endl;

	while (p > 0) {
		--p;
		ll su = hmin.top().fr;	int u = hmin.top().sc;	hmin.pop();
		if (hmin.empty()) {
			//cout << "!!!" << endl;
			break;
		}
		ll sv = hmin.top().fr;	int v = hmin.top().sc;	hmin.pop();
		// cout << "         " << su << " " << sv << "          " << su+sv << endl;
		printf("%d %d\n", u, v);
		ll len = min(ll(1e9), su+sv+1);
		hmin.push(mp(len + (su+sv), u));
	}

	rep(i, tmp_p)
		printf("%d %d\n", tmp_u, tmp_v);
	return 0;
}