#include <sstream>
#include <iostream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector< int > VI;
typedef pair< int, int > PI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

class BinaryPolynomialDivTwo {
   public:
   int countRoots(vector <int> a) {
      int n = a.size(), s0 = a[0], s1 = a[0];
      fab(i, 1, n-1) s1 += a[i];
      return (s0%2 == 0) + (s1%2 == 0);
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, countRoots(Arg0)); }
	void test_case_1() { int Arr0[] = {0, 1, 0, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(1, Arg1, countRoots(Arg0)); }
	void test_case_2() { int Arr0[] = {1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, countRoots(Arg0)); }
	void test_case_3() { int Arr0[] = {1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(3, Arg1, countRoots(Arg0)); }
	void test_case_4() { int Arr0[] = {1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, countRoots(Arg0)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        BinaryPolynomialDivTwo ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
