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


const int MAX_GAME = 2004;


double f[MAX_GAME][MAX_GAME];


class PointSystem {
public:
	double oddsOfWinning(int pointsToWin, int pointsToWinBy, int skill) {
		double w = skill / 100.0, ans = 0;
		filla(f, 0);
		f[0][0] = 1;
		for (int i = 0; i < MAX_GAME-1; ++i)
			for (int low = 0; low <= i; ++low) {
				int height = i - low;
				if (height >= pointsToWin && height-low >= pointsToWinBy)
					continue;
				if (low >= pointsToWin && low-height >= pointsToWinBy) {
					ans += f[low][height];
					continue;
				}
				f[low+1][height] += f[low][height] * w;
				f[low][height+1] += f[low][height] * (1-w);
			}
		return ans;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; int Arg2 = 40; double Arg3 = 0.352; verify_case(0, Arg3, oddsOfWinning(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 5; int Arg2 = 50; double Arg3 = 0.4999999999999998; verify_case(1, Arg3, oddsOfWinning(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 25; double Arg3 = 0.035714285714285705; verify_case(2, Arg3, oddsOfWinning(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	PointSystem ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
