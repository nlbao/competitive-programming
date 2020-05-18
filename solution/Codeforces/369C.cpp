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

// #pragma comment(linker, "/STACK:16777216")

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

const int MAX_N = int(1e5)+5;

int n;
bool ok[MAX_N];
vii e[MAX_N];
vi res;
int p[MAX_N];


bool dfs(int u) {
	ok[u] = false;
	bool ck = false;
	int szE = e[u].size();
	rep(i, szE) {
		int v = e[u][i].sc;
		if (ok[v]) {
			p[v] = e[u][i].fr;
			ck = dfs(v) || ck;
		}
	}
	if (u > 1 && p[u] == 2 && !ck) {
		res.pb(u);
		ck = true;
	}
	return ck;
}


int main() {
#ifdef DEBUG
	freopen("369C.in", "r", stdin);
	freopen("369C.out", "w", stdout);
#endif
	n = read();
	rep(i, n-1) {
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		e[x].pb(mp(t, y));
		e[y].pb(mp(t, x));
	}

	fill(ok, true);
	dfs(1);
	int m = res.size();
	printf("%d\n", m);
	rep(i, m) printf("%d ", res[i]);
	return 0;
}