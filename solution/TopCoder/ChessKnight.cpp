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


const int MAX_X = 10;
const int dx[8] = {-2, -2, -1, +1, +2, +2, +1, -1};
const int dy[8] = {-1, +1, +2, +2, +1, -1, -2, -2};


double f[2][MAX_X][MAX_X];


bool onBoard(int x, int y) {
	return (x >= 1) && (x <= 8) && (y >= 1) && (y <= 8);
}


class ChessKnight {
public:
	double probability(int x, int y, int n) {
		for (int i = 1; i <= 8; ++i)
			for (int j = 1; j <= 8; ++j)
				f[0][i][j] = 1;
		int t = 0;
		for (int turn = 0; turn < n; ++turn) {
			int tt = t;
			t ^= 1;
			for (int i = 1; i <= 8; ++i)
				for (int j = 1; j <= 8; ++j) {
					f[t][i][j] = 0;
					for (int k = 0; k < 8; ++k) {
						int x = i + dx[k];
						int y = j + dy[k];
						if (onBoard(x, y))
							f[t][i][j] += (1.0/8) * f[tt][x][y];
					}
				}
		}
		return f[t][x][y];
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.1875; verify_case(0, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; double Arg3 = 1.0; verify_case(1, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 10; double Arg3 = 0.0522148497402668; verify_case(2, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 50; double Arg3 = 8.356427906809618E-7; verify_case(3, Arg3, probability(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChessKnight ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
