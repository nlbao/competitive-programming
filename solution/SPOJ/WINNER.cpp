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


const int MAX_N = int(1e5)+5;
const int LIMIT = int(1e5)+5;


int n, nTurn;
int a[MAX_N], f[MAX_N], l[MAX_N], r[MAX_N], turn[MAX_N];
map<int, int> q;
int qsmall[LIMIT];
vector<int> listD[MAX_N];


void init() {
	nTurn = 0;
	filla(turn, 0);
	qsmall[0] = 0;
	for (int x = 1; x < LIMIT; ++x) {
		for (int y = x; y < LIMIT; y += x)
			listD[y].push_back(x);
		++nTurn;
		int ans = 1;
		foreach(it, listD[x]) {
			int v = qsmall[x-*it];
			turn[v] = nTurn;
			while (turn[ans] == nTurn) ++ans;
		}
		qsmall[x] = ans;
	}
}


int grundy(int x) {
	if (x < LIMIT)
		return qsmall[x];
	map<int, int>::iterator it = q.find(x);
	if (it != q.end())
		return it->second;

	vector<int> s;
	for (int i = 1; i*i <= x; ++i) {
		if (x%i == 0) {
			s.push_back(grundy(x-i));
			int j = x/i;
			if (j > i) s.push_back(grundy(x-j));
		}
	}
	++nTurn;
	int ans = 1;

	foreach(it, s) {
		int v = *it;
		turn[v] = nTurn;
		while (turn[ans] == nTurn) ++ans;
	}
	return q[x] = ans;
}


bool check(int a[], int n) {
	int s = 0;
	for (int i = 1; i <= n; ++i) {
		f[i] = grundy(a[i]);
		return 0;
		s ^= f[i];
	}
	return s != 0;
}


void solve() {
	l[0] = r[n+1] = 0;
	for (int i = 1; i <= n; ++i) l[i] = l[i-1] ^ f[i];
	for (int i = n; i >= 1; --i) r[i] = r[i+1] ^ f[i];
	int ansX = 0, ansA = -1;
	for (int i = n; i >= 1; --i) {
		if (i < n && a[i] == a[i+1]) continue;
		int t = l[i-1] ^ r[i+1] ^ 0, x = -1, g = grundy(0);
		if (g == t) x = max(x, a[i]);
		else {
			for (ll d = ansX+1; d*d <= a[i]; ++d)
				if (a[i] % d == 0) {
					g = grundy(a[i] - d);
					if (g == t) x = max(x, (int)d);
					int k = a[i] / d;
					if (k > x) {
						g = grundy(a[i] - k);
						if (g == t) x = k;
					}
				}
		}
		if (x > ansX) {
			ansX = x;
			ansA = a[i];
		}
	}
	printf("%d %d\n", ansX, ansA);
}


int main() {
#ifdef DEBUG
	// freopen("WINNER.in", "r", stdin);
	freopen("test.in", "r", stdin);
	freopen("WINNER.out", "w", stdout);
#endif
	init();

	n = read();
	for (int i = 1; i <= n; ++i)
		a[i] = read();
	sort(a+1, a+1+n);

	nTurn = 0;
	filla(turn, 0);
	if (check(a, n)) {
		printf("Bom\n");
		solve();
	}
	else printf("Cuoi\n");
	return 0;
}