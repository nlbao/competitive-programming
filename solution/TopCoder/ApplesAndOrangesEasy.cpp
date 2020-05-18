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


const int MAX_N = 2004;


int a[MAX_N];


class ApplesAndOrangesEasy {
public:
	int maximumApples(int n, int k, vector <int> info) {
		filla(a, 0);
		int m = info.size();
		for (int i = 0; i < m; ++i)
			a[info[i]] = 1;

		int ans = m, limit = k/2;

		for (int i = 1; i <= n; ++i) {
			int c = 0, e = min(n, i+k-1);
			for (int j = i; j <= e; ++j)
				if (a[j] == 1) ++c;
			if (c == limit) {
				for (int j = i; j <= e; ++j)
					if (a[j] == 0) a[j] = -1;
			}
		}

		for (int i = 1; i <= n; ++i) {
			int c = 0, e = min(n, i+k-1);
			for (int j = i; j <= e; ++j)
				if (a[j] == 1) ++c;
			for (int j = i; j <= e; ++j) {
				if (c >= limit) break;
				if (a[j] == 0) {
					a[j] = 1;
					++c;
					++ans;
				}
			}
			for (int j = i; j <= e; ++j)
				if (a[j] == 0) a[j] = -1;
		}
		return ans;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 2; int Arr2[] = {}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(0, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 3; int Arr2[] = {3, 8}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 2; verify_case(1, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 9; int Arg1 = 4; int Arr2[] = {1, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(2, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 9; int Arg1 = 4; int Arr2[] = {2, 4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 4; verify_case(3, Arg3, maximumApples(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 23; int Arg1 = 7; int Arr2[] = {3, 2, 9, 1, 15, 23, 20, 19}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(4, Arg3, maximumApples(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
 
// BEGIN CUT HERE
int main() {
	ApplesAndOrangesEasy ___test;
	___test.run_test(-1);
	// ___test.run_test(1);
	cin.get();
}
// END CUT HERE
