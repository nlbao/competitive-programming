#include <bits/stdc++.h>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

inline int read() {   int x;   scanf("%d",&x);   return x;   }
inline int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int MAX_N = 12;
const int MAX_M = 24;
const int MAX_M2 = MAX_M/2;
const int MAX_A = 2e5 + 4;


int m, n, limit1, limit2;
int v[MAX_M][MAX_N], w[MAX_N];
int a1[MAX_A][MAX_N], a2[MAX_A][MAX_N], b[MAX_N];
int id1[MAX_A], id2[MAX_A];
string state1[MAX_A], state2[MAX_A];


inline int pow3(int x) {
	int ans = 1;
	for (int i = 1; i <= x; ++i)
		ans *= 3;
	return ans;
}


bool cmp1(int i, int j) {
	return state1[i] < state1[j];
}


bool cmp2(int i, int j) {
	for (int k = 0; k < n; ++k)
		if (a2[i][k] != a2[j][k])
			return a2[i][k] < a2[j][k];
	return state2[i] < state2[j];
}


inline int cmpB(int pos) {
	for (int i = 0; i < n; ++i)
		if (a2[pos][i] < b[i]) return -1;
		else if (a2[pos][i] > b[i]) return 1;
	return 0;
}


inline string find(int pos) {
	string ans = "";
	for (int i = 0; i < n; ++i) {
		b[i] = w[i] - a1[pos][i];
		if (b[i] < 0) return ans;
	}
	int l = 0, r = limit2-1;
	while (l <= r) {
		int mid = (l+r)>>1;
		int x = id2[mid];
		int t = cmpB(x);
		if (t == 0) {
			ans = state2[x];
			r = mid-1;
		}
		else if (t == -1) l = mid+1;
		else r = mid-1;
	}
	return ans;
}


string solve() {
	int m2 = m/2, m1 = m-m2;

	limit1 = pow3(m1);
	filla(a1, 0);
	for (int mask = 0; mask < limit1; ++mask) {
		int x = mask;
		id1[mask] = mask;
		state1[mask] = "";
		for (int i = 0; i < m1; ++i) {
			int r = x%3;
			x /= 3;
			if (r == 0) {
				state1[mask] += "a";
				for (int k = 0; k < n; ++k)
					a1[mask][k] += v[i][k];
			}
			else if (r == 1) {
				state1[mask] += "b";
				for (int k = 1; k < n; k += 2)
					a1[mask][k] += v[i][k];
			}
			else {
				state1[mask] += "c";
				for (int k = 0; k < n; k += 2)
					a1[mask][k] += v[i][k];
			}
		}
	}

	limit2 = pow3(m2);
	filla(a2, 0);
	for (int mask = 0; mask < limit2; ++mask) {
		int x = mask;
		id2[mask] = mask;
		state2[mask] = "";
		for (int i = 0; i < m2; ++i) {
			int r = x%3;
			x /= 3;
			if (r == 0) {
				state2[mask] += "a";
				for (int k = 0; k < n; ++k)
					a2[mask][k] += v[m1+i][k];
			}
			else if (r == 1) {
				state2[mask] += "b";
				for (int k = 1; k < n; k += 2)
					a2[mask][k] += v[m1+i][k];
			}
			else {
				state2[mask] += "c";
				for (int k = 0; k < n; k += 2)
					a2[mask][k] += v[m1+i][k];
			}
		}
	}

	sort(id1, id1+limit1, cmp1);
	sort(id2, id2+limit2, cmp2);

	string ans = "-1";
	for (int i = 0; i < limit1; ++i) {
		int x = id1[i];
		if (ans != "-1" && i > 0 && state1[x] > state1[id1[i-1]]) break;
		if (m1 == m) {
			bool ok = true;
			for (int k = 0; k < n; ++k)
				if (w[k] != a1[x][k]) {
					ok = false;
					break;
				}
			if (ok) ans = state1[x];
			continue;
		}
		string t = find(x);
		if (t != "") {
			t = state1[x] + t;
			if (ans == "-1" || ans > t)
				ans = t;
		}
	}
	return ans;
}


int main() {
#ifdef DEBUG
	freopen("markov-and-game.in", "r", stdin);
	freopen("markov-and-game.out", "w", stdout);
#endif
	scanf("%d%d", &m, &n);
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			v[i][j] = read();
	for (int i = 0; i < n; ++i)
		w[i] = read();

	printf("%s\n", solve().c_str());
	return 0;
}