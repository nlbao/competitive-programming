// #pragma comment(linker, "/STACK:1024000000")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fori(i,a,b) for (ll i=(a); i<=(b); ++i)
#define ford(i,a,b) for (ll i=(a); i>=(b); --i)
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define err(x) cout << __LINE__ << ": " << #x << " = " << (x) << endl;
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define has(a, x) (a.find(x) != a.end())
#define all(x) x.begin(), x.end()
#define sz(a) int(a.size())
#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define endl '\n'


inline ll read() {	ll x;   cin >> x;   return x;   }


const int MAX_K = 1e5+5;
const int LIMIT = 1500;
const int OFFSET = 20;


int N;
int f[MAX_K], trace[MAX_K], ans[MAX_K], flen[MAX_K];
int f0[MAX_K], f0len[MAX_K], trace0[MAX_K];
bool isPlus[MAX_K];


void merge(deque<int> &dest, deque<int> &a) {
	while (!a.empty()) {
		dest.push_back(a.front());
		a.pop_front();
	}
}


deque<int> solve(int K, int &N, bool use0) {
	deque<int> ans;
	int x = use0 ? trace0[K] : trace[K];
	if (x == K) {
		for (int i = 0; i < K; ++i)
			ans.push_front(++N);
		return ans;
	}

	if (use0) {
		int x = trace0[K];
		int y = K / x;

		ans = solve(x, N, true);
		deque<int> ay = solve(y, N, true);
		merge(ans, ay);
	}
	else {
		if (isPlus[K]) {
			int x = trace[K];
			int y = K - x;
			int tmp = flen[x] - flen[y];

			deque<int> ax = solve(x, N, false);
			ans = solve(y, N, false);
			for (int i = 0; i < tmp; ++i)
				ans.push_back(++N);
			merge(ans, ax);
		}
		else {
			int x = trace[K];
			int y = K / x;

			ans = solve(x, N, false);
			deque<int> ay = solve(y, N, true);
			merge(ans, ay);
		}
	}

	return ans;
}


int main() {
#ifdef DEBUG
	freopen("MAKELIS.in", "r", stdin);
	freopen("MAKELIS.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);	cin.tie(0);
	cout.precision(9);
	cout.setf(ios::fixed, ios::floatfield);

	filla(isPlus, 0);
	for (int i = 0; i < MAX_K; ++i) {
		f[i] = trace[i] = i;
		flen[i] = 1;
		f0[i] = trace0[i] = i;
		f0len[i] = 1;
	}
	for (int i = 2; i < MAX_K; ++i) {
		for (int x = 1; x < LIMIT; ++x) {
			int y = i - x;
			if (y < 1) break;
			if (flen[y] > flen[x]) continue;
			int tmp = flen[x] - flen[y];
			if (f[x] + f[y] + tmp < f[i]) {
				f[i] = f[x] + f[y] + tmp;
				flen[i] = flen[x];
				trace[i] = x;
				isPlus[i] = 1;
			}
		}
		for (int j = i+i; j < MAX_K; j += i) {
			int d = j / i;
			if (d <= i) {
				if (f[i]+f0[d] < f[j]) {
					f[j] = f[i]+f0[d];
					flen[j] = flen[i]+f0len[d];
					trace[j] = i;
				}
				if (f0[i]+f0[d] < f0[j]) {
					f0[j] = f0[i]+f0[d];
					f0len[j] = f0len[i]+f0len[d];
					trace0[j] = i;
				}
			}
		}
		if (f[i] > 100) cout << i << " " << f[i] << endl;
	}

	int nTest = read();
	while (nTest--) {
		int K = read(), N = 0;
		deque<int> ans = solve(K, N, 0);
		cout << N << endl;
		while (!ans.empty()) {
			cout << ans.front() << " ";
			ans.pop_front();
		}
		cout << endl;
	}

	return 0;
}