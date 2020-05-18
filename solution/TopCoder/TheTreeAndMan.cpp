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


const int MAX_N = 2*int(1e3) + 44;
const ll MODULE = ll(1e9)+7;


ll mmod(ll x) {
	x %= MODULE;
	while (x < 0) x += MODULE;
	return x;
}


int id[MAX_N];
ll a[MAX_N], b[MAX_N], f[MAX_N][4];
vector<int> e[MAX_N];


void dfs(int u) {
	f[u][0] = 1;
	f[u][1] = f[u][2] = f[u][3] = 0;
	foreach(it, e[u]) {
		int v = *it;
		dfs(v);
		f[u][0] += f[v][0];
	}

	int m = (int)e[u].size();
	for (int i = 0; i < m; ++i) {
		int v = e[u][i];
		id[i] = v;
		a[i] = f[v][0];
	}
	b[0] = a[0];
	for (int i = 1; i < m; ++i)
		b[i] = mmod(b[i-1] + a[i]);
	b[m] = b[m-1];

	// calculate f[u][1]
	for (int i = 0; i < m; ++i) {
		ll s = mmod(a[i] * mmod(b[m] - b[i]));
		f[u][1] = mmod(f[u][1] + s);
	}
	for (int i = 0; i < m; ++i)
		f[u][1] = mmod(f[u][1] + f[id[i]][1]);

	// calculate f[u][2]
	for (int i = 0; i < m; ++i) {
		ll s = 0;
		for (int j = 0; j < m; ++j)
			if (j < i) {
				ll t = mmod(b[m]-b[j]-a[i]);
				s = mmod(s + a[j]*t);
			}
			else if (j > i) {
				ll t = mmod(b[m]-b[j]);
				s = mmod(s + a[j]*t);
			}
		f[u][2] = mmod(f[u][2] + mmod(s * f[id[i]][1]));
	}
	for (int i = 0; i < m; ++i)
		f[u][2] = mmod(f[u][2] + f[id[i]][2]);

	// calculate f[u][3]
	for (int i = 0; i < m; ++i)
		f[u][3] = mmod(f[u][3] + f[id[i]][2]);
}



class TheTreeAndMan {
public:
	int solve(vector <int> parent) {
		int n = parent.size() + 1;
		for (int i = 0; i < n; ++i) e[i].clear();
		for (int i = 0; i < n-1; ++i)
			e[parent[i]].push_back(i+1);
		dfs(0);
		ll ans = 0;
		for (int i = 0; i < n; ++i)
			ans = mmod(ans + f[i][3]);
		return ans;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {0,1,1,1,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, solve(Arg0)); }
	void test_case_1() { int Arr0[] = {0,0,2,2,2,4,0,4,7,2,10,11,9,0,1,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(1, Arg1, solve(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,2,2,3,1,0,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, solve(Arg0)); }
	void test_case_3() { int Arr0[] = {0,0,0,2,3,5,2,5,3,7,7,7,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, solve(Arg0)); }
	void test_case_4() { int Arr0[] = {0,0,1,2,2,2,1,4,2,9,0,1,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, solve(Arg0)); }
	void test_case_5() { int Arr0[] = {0,0,0,2,4,2,5,6,5,9,5,0,3,8,8,15,0,17,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(5, Arg1, solve(Arg0)); }
	void test_case_6() { int Arr0[] = {0,0,0,3,0,1,3,5,6,8,2,7,1,9,1,5,13,6,3,7,8,4,2,18,12,11,17,13,10,25,11,26,22,32,32,18,35,33,25,31,24,38,41,34,43,42,32,
43,31,35,47,49,36,35,39,42,36,39,47,53,40,61,60,43,47,61,51,56,67,69,53,53,63,56,71,55,76,73,70,74,67,76,64,80,68,85,78,
69,79,73,70,75,77,81,80,94,85,88,88,99,83,99,93,90,85,100,89,96,96,103,107,96,105,95,100,97,97}
; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9864; verify_case(6, Arg1, solve(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	TheTreeAndMan ___test;
	___test.run_test(-1);
	// ___test.run_test(1);
	cin.get();
}
// END CUT HERE
