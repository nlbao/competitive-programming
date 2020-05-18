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

 
class BracketExpressions {
public:
	string ifPossible(string expression) {
		
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "([]{})"; string Arg1 = "possible"; verify_case(0, Arg1, ifPossible(Arg0)); }
	void test_case_1() { string Arg0 = "(())[]"; string Arg1 = "possible"; verify_case(1, Arg1, ifPossible(Arg0)); }
	void test_case_2() { string Arg0 = "({])"; string Arg1 = "impossible"; verify_case(2, Arg1, ifPossible(Arg0)); }
	void test_case_3() { string Arg0 = "[]X"; string Arg1 = "impossible"; verify_case(3, Arg1, ifPossible(Arg0)); }
	void test_case_4() { string Arg0 = "([]X()[()]XX}[])X{{}}]"; string Arg1 = "possible"; verify_case(4, Arg1, ifPossible(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
    int main() {
        BracketExpressions ___test; 
        ___test.run_test(-1); 
       int X ;
       scanf("%d",&X) ;
    } 
// END CUT HERE
