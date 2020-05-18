#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> node;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 111;
const ll oo = 4e10;


int n, duration;
ll minStart;
int minH, minPos, minR;
int c[MAX_N], start[MAX_N], end[MAX_N];
ll f[MAX_N][MAX_N][MAX_N];
node a[MAX_N][MAX_N];
pii trace[MAX_N][MAX_N][MAX_N];
vector<int> ans;


void getAns(int h, int i, int j, ll pos, ll nTime) {
	if (h == n-1 || nTime >= duration) return;
	int k = trace[h][i][j].second;
	j = trace[h][i][j].first;
	// int k = trace[h][i][j];
	// cout << ": " << h << " " << i << " " << j << ": " << k << endl;
	if (k < 0) return;

	// if (h == n-2) j = k;

	pii u = a[h][i], v = a[h+1][j];

	if (nTime + u.second - pos >= duration)
		return;

	// cout << "getAns: " << h << " " << i << " " << j << " " << pos << " " << nTime << ": " << k << endl;

	if (v.first > pos) {
		// cout << "??? " << endl;
		nTime += v.first - pos;
		ans.push_back(v.first);
		getAns(h+1, j, k, v.first, nTime);
	}
	else {
		// if (pos == u.first) {
			++pos;
			++nTime;
		// }
		ans.push_back(pos);
		getAns(h+1, j, k, pos, nTime);
	}
}


inline int find(int i, ll limit) {
	if (i >= n) return -1;
	int l = 0, r = c[i]-1, ans = -1;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (a[i][mid].second > limit) {
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	return ans;
}


inline void update(int h, int i, int j) {
	pii u = a[h][i];
	f[h][i][j] = min(f[h][i][j], oo);
	if (f[h][i][j] < duration) return;
	// if (u.first < minStart || (u.first == minStart && h < minH)) {
	if (u.first < minStart) {
		minStart = u.first;
		minH = h;
		minPos = i;
		minR = j;
	}
}


int main() {
#ifdef DEBUG
	freopen("100703C.in", "r", stdin);
	freopen("100703C.out", "w", stdout);
#endif
	scanf("%d%d", &n, &duration);
	for (int i = 0; i < n; ++i) {
		int m = read();
		for (int k = 0; k < m; ++k)
			scanf("%d%d", &start[k], &end[k]);
		c[i] = 0;
		if (m > 0) {
			if (start[0] > 0) a[i][c[i]++] = node(0, start[0]);
			for (int k = 0; k < m-1; ++k)
				a[i][c[i]++] = node(end[k], start[k+1]);
			a[i][c[i]++] = node(end[m-1], oo);
		}
		else a[i][c[i]++] = node(0, oo);
	}

	minStart = oo - duration, minH = 0, minPos = c[0]-1, minR = 0;
	filla(f, 0);
	for (int h = n-1; h >= 0; --h)
		for (int i = 0; i < c[h]; ++i) {
			pii u = a[h][i];
			if (h == n-1) {
				f[h][i][0] = u.second - u.first;
				trace[h][i][0] = pii(-1, -1);
				update(h, i, 0);
				// cout << "	" << h << " " << i << ": " << f[h][i][0] << endl;
				continue;
			}

			for (int j = c[h+1]-1; j >= 0; --j) {
				f[h][i][j] = u.second - u.first;
				trace[h][i][j] = pii(-1, -1);
				if (j < c[h+1]-1 && f[h][i][j+1] > f[h][i][j]) {
					f[h][i][j] = f[h][i][j+1];
					trace[h][i][j] = trace[h][i][j+1];
				}
				// cout << "	" << h << " " << i << " " << j << ": " << f[h][i][j] << endl;

				if (f[h][i][j] >= oo) continue;

				pii v = a[h+1][j];
				if (u.first+1 >= v.second || u.second < v.first) continue;

				if (h == n-2) {
					ll tmp = f[h+1][j][0] + v.first - u.first;
					if (tmp > f[h][i][j]) {
						f[h][i][j] = tmp;
						trace[h][i][j] = pii(j, 0);
					}
					// cout << "	" << h << " " << i << " " << j << ": " << f[h][i][j] << ", " << tmp << ", " << trace[h][i][j] << endl;
					continue;
				}

				if (f[h][i][j] >= oo) continue;

				ll t = max(u.first, v.first) + 1;
				if (v.first <= u.first) {
					++t;
					// if (v.second == t) continue;
				}
				if (v.second < t) continue;
				int k = find(h+2, t);
				if (k < 0) continue;
				ll tmp = f[h+1][j][k] + v.first - u.first;
				if (tmp > f[h][i][j]) {
					f[h][i][j] = tmp;
					trace[h][i][j] = pii(j, k);
					// cout << "	" << h << " " << i << " " << j << ": " << k << " " << f[h][i][j] << endl;
				}
			}

			for (int j = c[h+1]-1; j >= 0; --j)
				update(h, i, j);
		}

	getAns(minH, minPos, minR, a[minH][minPos].first, 0);
	n = ans.size();
	printf("%d\n", (int)minStart);
	printf("%d %d\n", minH+1, n);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	return 0;
}