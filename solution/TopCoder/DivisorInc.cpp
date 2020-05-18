#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> VI;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_M = 100010;

queue< int > q;
int f[MAX_M];

void add(int x, int ff) {
   if ((x > MAX_M) || (f[x] > 0)) return;
   q.push(x);
   f[x] = ff;
}

class DivisorInc {
   public:
   int countOperations(int n, int m) {
      if (n == m) return 0;
      fill(f, 0);
      add(n, 0);
      while (!q.empty()) {
         int u = q.front();   q.pop();
         fab(i, 2, int(sqrt(u))) {
            if (u+i > m) break;
            else if (u%i == 0) {
               add(u+i, f[u]+1);
               add(u+u/i, f[u]+1);
            }
         }
         if (f[m] > 0) {
            while (!q.empty()) q.pop();
            return f[m];
         }
      }
      return -1;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 24; int Arg2 = 5; verify_case(0, Arg2, countOperations(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 576; int Arg2 = 14; verify_case(1, Arg2, countOperations(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 8748; int Arg1 = 83462; int Arg2 = 10; verify_case(2, Arg2, countOperations(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 235; int Arg1 = 98234; int Arg2 = 21; verify_case(3, Arg2, countOperations(Arg0, Arg1)); }
	void test_case_4() { int Arg0 = 4; int Arg1 = 99991; int Arg2 = -1; verify_case(4, Arg2, countOperations(Arg0, Arg1)); }
	void test_case_5() { int Arg0 = 82736; int Arg1 = 82736; int Arg2 = 0; verify_case(5, Arg2, countOperations(Arg0, Arg1)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        DivisorInc ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
