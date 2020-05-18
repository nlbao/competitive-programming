#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string.h>
#include <utility>
#include <deque>
#include <math.h>

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

double sqr(double x) { return x*x; }

double dist(int x1, int y1, int x2, int y2) {
   return sqr(x1-x2)+sqr(y1-y2);
}

class Shouting {
   public:
   double shout(vector <int> x, vector <int> y) {
      int n = x.size();
      double f[MAX_N][MAX_N];
      double res = 0;
      fab(i, 0, n-1)
         fab(j, 0, n-1)
            f[i][j] = dist(x[i], y[i], x[j], y[j]);
      fab(k, 0, n-1)
         fab(i, 0, n-1)
            fab(j, 0, n-1)
               f[i][j] = min(f[i][j], max(f[i][k], f[k][j]));
      fab(i, 0, n-1)
         fab(j, 0, n-1)
            res = max(res, f[i][j]);
      return sqrt(res);
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {-2000,-2000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3000,3000}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(0, Arg2, shout(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,3,3,3,3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {2,3,4,3,9,8,1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 4.0; verify_case(1, Arg2, shout(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5,0,-5,0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0,5,0,-5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 7.0710678118654755; verify_case(2, Arg2, shout(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {17}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1912}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); double Arg2 = 0.0; verify_case(3, Arg2, shout(Arg0, Arg1)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        Shouting ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
