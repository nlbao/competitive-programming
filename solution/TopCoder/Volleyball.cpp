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


const int MAX_POINT = 1004;
const int WIN_POINT = 15;
const int WIN_LEAD = 2;


double f[MAX_POINT][MAX_POINT];
double p;


double cal(int x, int y) {
	if (max(x, y) >= MAX_POINT)
		return 0;
	if (f[x][y] != -1) return f[x][y];
	if (x >= WIN_POINT && x-y >= WIN_LEAD)
		return 1;
	if (y >= WIN_POINT && y-x >= WIN_LEAD)
		return 0;
	f[x][y] = p * cal(x+1, y) + (1-p) * (1 - cal(y+1, x));
	return f[x][y];
}


class Volleyball {
public:
	double win(int sScore, int rScore, double probWinServe) {
		p = probWinServe;
		for (int i = 0; i < MAX_POINT; ++i)
			for (int j = 0; j < MAX_POINT; ++j)
				f[i][j] = -1;
		return cal(sScore, rScore);
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 13; int Arg1 = 13; double Arg2 = .5; double Arg3 = 0.5; verify_case(0, Arg3, win(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 14; double Arg2 = 0.01; double Arg3 = 3.355704697986578E-27; verify_case(1, Arg3, win(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 8; int Arg1 = 12; double Arg2 = 0.4; double Arg3 = 0.046377890909090946; verify_case(2, Arg3, win(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 3; double Arg2 = 0.01; double Arg3 = 0.6662085066547871; verify_case(3, Arg3, win(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
 
// BEGIN CUT HERE
int main() {
	Volleyball ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
