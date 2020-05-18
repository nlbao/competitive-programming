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



class FoxAndSorting {
   public:
   long long get(long long idx) {
    
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 10LL; long long Arg1 = 100000000LL; verify_case(0, Arg1, get(Arg0)); }
	void test_case_1() { long long Arg0 = 1000000000000000000LL; long long Arg1 = 999999999999999999LL; verify_case(1, Arg1, get(Arg0)); }
	void test_case_2() { long long Arg0 = 58LL; long long Arg1 = 100000000100LL; verify_case(2, Arg1, get(Arg0)); }
	void test_case_3() { long long Arg0 = 314159265358979LL; long long Arg1 = 646003042230121105LL; verify_case(3, Arg1, get(Arg0)); }
	void test_case_4() { long long Arg0 = 271828182845904523LL; long long Arg1 = 132558071125756493LL; verify_case(4, Arg1, get(Arg0)); }

// END CUT HERE

};
 
 // BEGIN CUT HERE 
   int main()
        {
        FoxAndSorting ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
