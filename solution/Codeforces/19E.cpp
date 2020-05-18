#include <cstdio>
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
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = int(1e4)+4;

int n, m, crrTurn;
int a[MAX_N], b[MAX_N], turn[MAX_N];
int p[MAX_N], f[MAX_N], p_tmp[MAX_N], f_tmp[MAX_N];
vector<int> ans;
bool ok[MAX_N];


int getRoot(int u) {
	if (p[u] < 1) return u;
	else {
		int r = p[u];
		p[u] = getRoot(p[u]);
		f[u] ^= f[r];
	}
	return p[u];
}


bool connect(int x, int y) {
	int px = getRoot(x), py = getRoot(y);
	if (px != py) {
		p[px] = py;
		f[px] = f[x] ^ 1 ^ f[y];
	}
	else if ((f[x] ^ f[y]) == 0)
		return false;
	return true;
}


int getRoot_tmp(int u) {
	if (turn[u] != crrTurn) {
		p_tmp[u] = p[u];
		f_tmp[u] = f[u];
		turn[u] = crrTurn;
	}
	if (p_tmp[u] < 1) return u;
	else {
		int r = p_tmp[u];
		p_tmp[u] = getRoot_tmp(p_tmp[u]);
		f_tmp[u] ^= f_tmp[r];
	}
	return p_tmp[u];
}


bool connect_tmp(int x, int y) {
	int px = getRoot_tmp(x), py = getRoot_tmp(y);
	if (px != py) {
		p_tmp[px] = py;
		f_tmp[px] = f_tmp[x] ^ 1 ^ f_tmp[y];
	}
	else if ((f_tmp[x] ^ f_tmp[y]) == 0)
		return false;
	return true;
}


int main() {
#ifdef DEBUG
	freopen("19E.in", "r", stdin);
	freopen("19E.out", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i)
		scanf("%d%d", &a[i], &b[i]);

	ans.clear();
	filla(turn, 0);
	crrTurn = 0;
	int block_size = (int)sqrt(n);
	for (int i = 0, j = 0; i < m; i = j+1) {
		j = min(i+block_size, m)-1;
		for (int k = 1; k <= n; ++k) {
			p[k] = -1;
			f[k] = 0;
		}
		bool ok = true;
		for (int k = 0; k < i; ++k)
			ok = ok && connect(a[k], b[k]);
		for (int k = j+1; k < m; ++k)
			ok = ok && connect(a[k], b[k]);
		if (!ok) continue;
		for (int pos = i; pos <= j; ++pos) {
			ok = true;
			++crrTurn;
			for (int k = i; k < pos; ++k)
				ok = ok && connect_tmp(a[k], b[k]);
			for (int k = pos+1; k <= j; ++k)
				ok = ok && connect_tmp(a[k], b[k]);
			if (ok) ans.push_back(pos);
		}
	}

	n = (int)ans.size();
	printf("%d\n", n);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]+1);
	return 0;
}