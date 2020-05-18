#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = int(1e6)+6;
const int MAX_M = int(1e5)+5;


int n, m;
int x[MAX_N], y[MAX_N];
int cx[MAX_N], cy[MAX_N];
pair<pii, int> a[MAX_N];
int turn[MAX_N];


void init(int dx, int &nC, int c[]) {
	nC = 0;
	int nTurn = 0;
	for (int i = 0; i < MAX_N; ++i)
		c[i] = 0;
	filla(turn, 0);
	for (int i = 0; i < n; ++i) {
		if (c[i] > 0) continue;
		int x = i;
		c[x] = ++nC;
		++nTurn;
		while (turn[x] != nTurn) {
			cout << "		" << x << " " << nC << endl;
			turn[x] = nTurn;
			c[x] = nC;
			x = (x+dx) % n;
		}
	}
	cout << "!!!" << endl;
}


int main() {
#ifdef DEBUG
	freopen("492E.in", "r", stdin);
	freopen("492E.out", "w", stdout);
#endif
	int dx, dy;
	scanf("%d%d%d%d", &n, &m, &dx, &dy);
	for (int i = 0; i < m; ++i)
		scanf("%d%d", &x[i], &y[i]);

	// init
	int ncx, ncy;
	init(dx, ncx, cx);
	init(dy, ncy, cy);

	// solve
	for (int i = 0; i < m; ++i) {
		a[i] = make_pair(make_pair(cx[x[i]], cy[y[i]]), i);
		cout << x[i] << " " << y[i] << ": " << cx[x[i]] << " " << cy[y[i]] << endl;
	}
	sort(a, a+m);

	int ans = 0, posX, posY;
	for (int i = 0, j = 0; i < m; i = j) {
		j = i;
		int cnt = 0;
		while (j < m && a[j].first == a[i].first) {
			++cnt;
			++j;
		}
		if (cnt > ans) {
			ans = cnt;
			posX = x[a[i].second];
			posY = y[a[i].second];
		}
	}
	printf("%d %d\n", posX, posY);
	return 0;
}