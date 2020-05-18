#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 222;



int n, m, limit;


inline void updateResult() {
	if (sum <= maxSum) return;
	maxSum = sum;
	ansH.clear();
	for (int i = 0; i < nH; ++i)
		ansH.push_back(h[i]);
}


void tryf(int pos) {
	if (pos > nA) {
		updateResult();
		return;
	}
	++nTime;
	if (nTime > limit) {
		updateResult();
		return;
	}
	if (sum > maxSum)
		updateResult();
	
}


int solve(int s) {
	queue<int> q;
	q.push(s);
	ok[s] = false;
	nA = 0;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		a[++nA] = u;
		foreach(it, e[u]) {
			int v = *it;
			if (!ok[v]) continue;
			q.push(v);
			ok[v] = false;
		}
	}

	limit = 1e5 / nA;
	nTime = 0;
	sum = 0;
	maxSum = 0;
	filla(inH, false);
	tryf(1);
	return maxSum;
}


int main() {
#ifdef DEBUG
	freopen("VMCUT.in", "r", stdin);
	freopen("VMCUT.out", "w", stdout);
#endif
	n = read()
	int t = read();
	m = t;
	while (t--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y) continue;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	int ansSum = 0;
	vector<int> h;
	filla(ok, true);
	for (int i = 1; i <= n; ++i)
		if (ok[i]) {
			solve(i);
			ansSum += maxSum;
			for (int k = 0; k < (int)ansH.size(); ++k)
				h.push_back(ansH[k]);
		}
	printf("%d\n", ansSum);
	for (int i = 0; i < (int)h.size(); ++i)
		printf("%d ", h[i]);
	return 0;
}