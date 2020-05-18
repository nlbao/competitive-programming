#pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second
#define endl '\n'

inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_N = 55;
const int MAX_C = 111*MAX_N;
const int oo = 1e5;


int n, limit;
vector<pii> tmp;
int w[MAX_N], id[MAX_N];
int preOk[MAX_C], preF[MAX_N][MAX_C], preG[MAX_N][MAX_C];
int f[MAX_N][MAX_C], g[MAX_N][MAX_C];
bool ok[MAX_C];
vector<int> a, b;


void build() {
	for (int x = 0; x <= limit; ++x)
		f[n+1][x] = -oo, g[n+1][x] = oo;
	f[n+1][0] = g[n+1][0] = 0;
	filla(preF, 0);
	filla(preG, 0);
	for (int i = n; i >= 1; --i) {
		for (int x = 0; x <= limit; ++x) {
			f[i][x] = f[i+1][x];
			g[i][x] = g[i+1][x];
			preF[i][x] = preG[i][x] = 0;
			int y = x-w[i];
			if (y < 0) continue;
			if (f[i+1][y]+1 > f[i][x]) {
				f[i][x] = f[i+1][y]+1;
				preF[i][x] = i;
			}
			if (g[i+1][y]+1 < g[i][x]) {
				g[i][x] = g[i+1][y]+1;
				preG[i][x] = i;
			}
		}
	}
}


void getList(vector<int> &a, int x, int pre[]) {
	while (x > 0) {
		a.push_back(pre[x]);
		x -= w[pre[x]];
	}
}


void getList_2(vector<int> &a, int i, int x, int pre[][MAX_C]) {
	while (x > 0) {
		int k = pre[i][x];
		if (k) {
			a.push_back(k);
			x -= w[k];
		}
		++i;
	}
}


void printList(vector<int> &a) {
	int n = a.size();
	cout << n << " ";
	for (int i = 0; i < n; ++i)
		cout << id[a[i]] << " ";
	cout << endl;
}


int main() {
#ifdef DEBUG
	freopen("100430F.in", "r", stdin);
	freopen("100430F.out", "w", stdout);
#else
	freopen("knapsack.in", "r", stdin);
	freopen("knapsack.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> w[i];
		tmp.push_back(pii(w[i], i));
	}
	cin >> limit;

	sort(tmp.begin(), tmp.end());
	for (int i = 0; i < n; ++i) {
		w[i+1] = tmp[i].fr;
		id[i+1] = tmp[i].sc;
	}
	build();

	filla(ok, false);
	filla(preOk, 0);
	ok[0] = true;
	for (int i = 1; i <= n; ++i) {
		for (int x = 0; x <= limit-w[i]; ++x) {
			if (!ok[x]) continue;
			int l = max(limit - x - w[i] + 1, 1);
			int r = limit - x;
			if (l > r) continue;
			int maxF = -oo, minG = oo;
			int maxK, minK;
			for (int k = 0; k < l; ++k)
				if (f[i+1][k] > maxF) {
					maxF = f[i+1][k];
					maxK = k;
				}
			for (int k = l; k <= r; ++k)
				if (g[i+1][k] < minG) {
					minG = g[i+1][k];
					minK = k;
				}
			if (maxF < minG) continue;
			cout << "NO\n";
			cout << "3\n";
			a.clear();
			b.clear();
			a.push_back(i);
			getList(a, x, preOk);
			getList_2(a, i+1, maxK, preF);
			getList(b, x, preOk);
			getList_2(b, i+1, minK, preG);
			printList(a);
			printList(b);
			return 0;
		}

		for (int x = limit-w[i]; x >= 0; --x) {
			if (!ok[x]) continue;
			int y = x+w[i];
			if (ok[y]) continue;
			ok[y] = true;
			preOk[y] = i;
		}
	}

	cout << "YES\n";

	return 0;
}