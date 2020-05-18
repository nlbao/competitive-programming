#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
 
using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PI;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define size(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second
 
class TheDivisionGame {
    public:
    long long countWinningIntervals(int L, int R) {
    
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 9; int Arg1 = 10; long long Arg2 = 2LL; verify_case(0, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 5; long long Arg2 = 9LL; verify_case(1, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 6; long long Arg2 = 13LL; verify_case(2, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 100; long long Arg2 = 4345LL; verify_case(3, Arg2, countWinningIntervals(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 12566125; int Arg1 = 12567777; long long Arg2 = 1313432LL; verify_case(4, Arg2, countWinningIntervals(Arg0, Arg1)); }

// END CUT HERE

};
 
 // BEGIN CUT HERE 
    int main()
        {
        TheDivisionGame ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
