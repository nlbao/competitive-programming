#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>

using namespace std;

typedef long long ll;

#define fab(i,a,b) for(int i = (a); i <= (b); ++i)
#define fba(i,b,a) for(int i = (b); i >= (a); --i)
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x, y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_N = 100;

int f[MAX_N][MAX_N];

vector<int> pare(string s) {
   vector<int> res;
   char t[MAX_N*10];
   strcpy(t, s.c_str());
   char *p = strtok(t, " ");
   while (p != NULL) {
      res.pb(atoi(p));
      p = strtok(NULL, " ");
   }
   return res;
}

class CostMatrix {
   public:
   int leastTotalCost(vector <string> matrix) {
      int n = matrix.size();
      fab(i, 0, n-1) {
         vector<int> w = pare(matrix[i]);
         fab(j, 0, n-1)
            f[i][j] = w[j];
      }

      fab(i, 0, n-1)
         fab(j, 0, n-1)
            fab(k, 0, n-1)
               if (f[i][k]+f[k][j] < f[i][j]) return -1;

      int res = 0;
      fab(i, 0, n-1)
         fab(j, i+1, n-1) {
            bool use = true;
            fab(k, 0, n-1)
               if ((k != i) && (k != j) && (f[i][k]+f[j][k] == f[i][j]))
                  use = false;
            if (use) res += f[i][j];
         }
      return res;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"0 2 2",
 "2 0 2",
 "2 2 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(0, Arg1, leastTotalCost(Arg0)); }
	void test_case_1() { string Arr0[] = {"0 6 15 2 6",
 "6 0 9 8 12",
 "15 9 0 16 18",
 "2 8 16 0 4",
 "6 12 18 4 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 55; verify_case(1, Arg1, leastTotalCost(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 1 6 17 26 13 7 16",
 "1 0 5 16 25 12 7 15",
 "6 5 0 21 21 8 12 11",
 "17 16 21 0 41 28 23 31",
 "26 25 21 41 0 13 32 10",
 "13 12 8 28 13 0 19 3",
 "7 7 12 23 32 19 0 22",
 "16 15 11 31 10 3 22 0"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 69; verify_case(2, Arg1, leastTotalCost(Arg0)); }
	void test_case_3() { string Arr0[] = {"0 1 3",
 "1 0 1",
 "3 1 0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = -1; verify_case(3, Arg1, leastTotalCost(Arg0)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        CostMatrix ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
