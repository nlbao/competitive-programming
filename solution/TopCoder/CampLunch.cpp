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

const ll MODULE = 1e9+7;
const int MAX_N = 20;
const int MAX_M = 16;
const int MAX_P = (1<<MAX_M) + 14;


int n, m, nMask, fullMask;
int pos[MAX_N][MAX_N], edge[MAX_N][MAX_P];
ll f[2][MAX_P], g[2][MAX_P];
vector<int> subsets[MAX_P];
bool check1[MAX_P];


void init_check1() {
	for (int x = 0; x < nMask; ++x) {
		bool even = true;
		for (int i = 0; i < m; ++i)
			if ((1&(x>>i)) == 0) {
				if (!even) break;
			}
			else even = !even;
		check1[x] = even;
	}
}


inline void updateG(int i) {
	for (int x = 0; x < nMask; ++x) {
		if (g[i][x] == 0) continue;
		int y = 0;
		do {
			if (y != x)
				g[i][y] += g[i][x];
			y = (y+1+~x)&x;
		} while (y != 0);
	}
	for (int x = 0; x < nMask; ++x)
		g[i][x] %= MODULE;
}


class CampLunch {
public:
	int count(int N, int M, vector <string> a) {
		// init
		n = N;	m = M;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				pos[i][a[i][j]-'A'] = j;

		nMask = 1<<m;
		fullMask = nMask-1;
		init_check1();
		for (int x = 0; x < nMask; ++x) {
			subsets[x].clear();
			int y = 0;
			do {
				if (check1[x^y])
					subsets[x].push_back(y);
				y = (y+1+~x)&x;
			} while (y != 0);
		}
		for (int i = 1; i < n; ++i)
			for (int x = 0; x < nMask; ++x) {
				int t = 0;
				for (int k = 0; k < m; ++k)
					if (x&(1<<k))
						t |= (1<<pos[i-1][a[i][k]-'A']);
				edge[i][x] = t;
			}

		filla(f, 0);
		filla(g, 0);
		for (int x = 0; x < nMask; ++x) {
			if (check1[x]) f[0][x] = 1;
			else f[0][x] = 0;
			int y = x ^ fullMask;
			g[0][y] = (g[0][y] + f[0][x]) % MODULE;
		}
		updateG(0);

		// solve
		for (int turn = 1, i = 1; turn < n; ++turn) {
			for (int x = 0; x < nMask; ++x)
				f[i][x] = g[i][x] = 0;
			for (int x = 0; x < nMask; ++x) {
				foreach(it, subsets[x]) {
					int y = *it;
					int t = edge[turn][y];
					f[i][x] += g[i^1][t];
				}
				f[i][x] %= MODULE;
				int y = x ^ fullMask;
				g[i][y] = (g[i][y] + f[i][x]) % MODULE;
			}
			updateG(i);
			i ^= 1;
		}

		// get ans
		ll ans = 0;
		for (int x = 0, i = (n-1)&1; x < nMask; ++x)
			ans = (ans + f[i][x]) % MODULE;
		return ans;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 2; string Arr2[] = {"AB","AB"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 7; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 3; string Arr2[] = {"ABC","ABC"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 22; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; string Arr2[] = {"ABC","BAC"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 21; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 1; string Arr2[] = {"A"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 1; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 1; int Arg1 = 10; string Arr2[] = {"ABDEFHIGJC"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 89; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 16; int Arg1 = 16; string Arr2[] = {"ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP","ABCDEFGHIJKLMNOP"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 950052677; verify_case(5, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arg0 = 15; int Arg1 = 16; string Arr2[] = {"BGCFDHOLEIKMPNAJ", "HAGDLBMINJEFKCOP", "JOBALEHDGMICNKFP", "LEFAJGKBOCHMIDPN", "EPMCAGDBJOIFKLHN", "LCBDJNFPEIHAGKMO", "PKMGBONLIACEDHJF", "IOBEPMNCJGDAHLKF", "KINACGPJOMFDEBLH", "MIFBPGDONKEAJHCL", "HMJOEIBPKGFDACNL", "MJLAIBKPFOGCHNED", "KAIGOBDMFELNCPHJ", "LBMDOHPANKCJEFGI", "PODHEAMNGBIFJLCK"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 110200390; verify_case(6, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	CampLunch ___test;
	___test.run_test(-1);
	// ___test.run_test(3);
	// ___test.run_test(1);
	// ___test.run_test(2);
	// ___test.run_test(6);
	cin.get();
}
// END CUT HERE
