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

const int MAX_N = 3*int(1e5)+5;

int n, m;
pii a[MAX_N];
int crr[MAX_N], szE[MAX_N], res[MAX_N];
vi e[MAX_N];

class heap_min {
public:
	bool operator() (const int &i, const int &j) const {
		return e[j][crr[j]] < e[i][crr[i]];
	}
};
priority_queue<int, vi, heap_min> h;




int main() {
#ifdef DEBUG
	freopen("369E.in", "r", stdin);
	freopen("369E.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	rep(i, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = mp(x, y);
	}
	sort(a, a+n);

	rep(i, m) {
		e[i].clear();
		crr[i] = res[i] = 0;
		read(szE[i]);
		rep(j, szE[i]) {
			int x = read();
			e[i].pb(x);
		}
		if (szE[i]) h.push(i);
	}

	int pre = -1;
	rep(i, n) {
		if (h.empty()) break;
		int l = a[i].fr, r = a[i].sc;
		if (r <= pre) continue;
		l = max(l, pre+1);
		pre = r;
		while (!h.empty()) {
			int u = h.top();
			if (e[u][crr[u]] > r) break;
			cout << "      !!!!! " << e[u][crr[u]] << endl;
			h.pop();
			while (crr[u] < szE[u] && e[u][crr[u]] < l) ++crr[u];
			if (crr[u] > szE[u]) continue;
			if (e[u][crr[u]] <= r) {
				++res[u];
				while (crr[u] < szE[u] && e[u][crr[u]] <= r) ++crr[u];
			}
			if (crr[u] < szE[u]) h.push(u);
			cout << "   " << u << "       " << crr[u] << "   " << szE[u] << "        " << l << " " << r << "        " << e[u][crr[u]] << endl;
		}
	}

	rep(i, m) printf("%d\n", res[i]);
	return 0;
}