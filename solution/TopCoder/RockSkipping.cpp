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


const int MAX_N = 55;


double f[2][MAX_N];


class RockSkipping {
public:
	double probability(string pads, int maxDist) {
		int n = pads.size();
		filla(f, 0);
		f[0][0] = 1;
		int t = 0;
		for (int turn = 0; turn < maxDist; ++turn) {
			int tt = t;
			t ^= 1;
			double p = 1.0/(maxDist-turn);
			for (int i = 0; i < n; ++i) f[t][i] = 0;
			for (int i = 0; i < n; ++i) {
				if (pads[i] == 'X') continue;
				for (int x = 1; x <= maxDist-turn; ++x) {
					int j = (i+x)%n;
					if (pads[j] == 'X') continue;
					f[t][j] += f[tt][i] * p;
				}
			}
		}
		double ans = 0;
		for (int i = 0; i < n; ++i)
			if (pads[i] == '.')
				ans += f[t][i];
		return ans * 100;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "."; int Arg1 = 100; double Arg2 = 100.0; verify_case(0, Arg2, probability(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "...X"; int Arg1 = 2; double Arg2 = 50.0; verify_case(1, Arg2, probability(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "........................X"; int Arg1 = 50; double Arg2 = 11.60725450562586; verify_case(2, Arg2, probability(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "...X......XXXX...XX.X..X...XX..."; int Arg1 = 48; double Arg2 = 5.408479511004734E-8; verify_case(3, Arg2, probability(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	RockSkipping ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
