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

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


const int MAX_N = 55;

int top, nCount, nC;
vector<int> e[MAX_N], tmp_e[MAX_N];
ll ans[MAX_N];
int p[MAX_N], num[MAX_N], low[MAX_N], stack[MAX_N], c[MAX_N];
bool ok[MAX_N], done[MAX_N];


void dfs(int u) {
	ok[u] = false;
	ans[u] = 1;
	ll g = 1;
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		dfs(v);
		if (g == 0) g = 1;
		g *= ans[v];
	}
	ans[u] += g;
}


void dfs_scc(int u) {
	ok[u] = false;
	stack[++top] = u;
	num[u] = low[u] = ++nCount;
	for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
		int v = e[u][i];
		if (done[v]) continue;
		if (ok[v]) {
			dfs_scc(v);
			low[u] = min(low[u], low[v]);
		}
		else low[u] = min(low[u], num[v]);
	}

	if (low[u] == num[u]) {
		int v = -1;
		while (top > 0 && v != u) {
			v = stack[top--];
			c[v] = nC;
			done[v] = true;
		}
		++nC;
	}
}


class InvariantSets {
public:
	long long countSets(vector <int> f) {
		int n = (int)f.size();
		for (int i = 0; i < n; ++i) {
			e[i].clear();
			p[i] = -1;
		}
		for (int i = 0; i < n; ++i)
			if (f[i] != i) {
				e[f[i]].push_back(i);
				p[i] = f[i];
			}

		fill(ok, true);
		fill(done, false);
		top = nCount = nC = 0;
		for (int i = 0; i < n; ++i) c[i] = -1;
		for (int i = 0; i < n; ++i) if (p[i] == -1) dfs_scc(i);
		for (int i = 0; i < n; ++i) if (ok[i]) dfs_scc(i);

		for (int u = 0; u < n; ++u) {
			tmp_e[u].clear();
			for (int i = 0, sz = (int)e[u].size(); i < sz; ++i)
				tmp_e[u].push_back(e[u][i]);
			e[u].clear();
			p[u] = -1;
		}
		for (int u = 0; u < n; ++u)
			for (int i = 0, sz = (int)tmp_e[u].size(); i < sz; ++i) {
				int v = tmp_e[u][i];
				if (c[u] != c[v]) {
					e[c[u]].push_back(c[v]);
					p[c[v]] = c[u];
				}
			}

		ll res = 1;
		fill(ok, true);
		for (int i = 0; i < nC; ++i)
			if (ok[i] && p[i] == -1) {
				dfs(i);
				res *= ans[i];
			}
		return res;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,0,0,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(0, Arg1, countSets(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 2LL; verify_case(1, Arg1, countSets(Arg0)); }
	void test_case_2() { int Arr0[] = {0,0,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 5LL; verify_case(2, Arg1, countSets(Arg0)); }
	void test_case_3() { int Arr0[] = {0,1,2,3,4,5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 64LL; verify_case(3, Arg1, countSets(Arg0)); }
	void test_case_4() { int Arr0[] = {12, 10, 0, 4, 0, 6, 3, 8, 9, 14, 1, 5, 6, 12, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 90LL; verify_case(4, Arg1, countSets(Arg0)); }
	void test_case_5() { int Arr0[] = {1, 9, 6, 8, 13, 7, 12, 4, 5, 13, 0, 9, 5, 2, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); long long Arg1 = 55LL; verify_case(5, Arg1, countSets(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
    int main() {
        InvariantSets ___test; 
        ___test.run_test(-1); 
       int X ;
       scanf("%d",&X) ;
    } 
// END CUT HERE
