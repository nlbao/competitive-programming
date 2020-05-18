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

const int MAX_N = 60;
const int MAX_A = MAX_N*1007;
const double oo = 1000000000;

int n;
double f[2][MAX_N][2*MAX_A];

class MergersDivTwo {
   public:
   double findMaximum(vector <int> a, int p) {
      n = a.size();
      int sa = 0;
      fab(i, 0, n) {
         a[i] += 1007;
         sa += a[i];
      }

      fab(j, 0, n)
         fab(k, 0, sa) f[0][j][k] = -oo;
      fab(k, 0, sa) f[0][0][k] = 0;
      f[0][1][a[1]] = 0;

      int t = 0;
      fab(i, 1, n-1) {
         int tt = t;
         t = (t+1)%2;
         fab(j, 0, n)
            fab(k, 0, sa) f[t][j][k] = -oo;

         fab(j, 1, i)
            fab(k, a[i], sa)
               f[t][j][k] = f[tt][j-1][k-a[i]];

         f[t][1][a[i]] = f[tt][0][0];

         fab(j, p, i)
            fab(k, 0, sa)
               f[t][0][0] = max(f[t][0][0], f[t][j][k]+double(k)/double(j)-1007);
      }
      printf("%5.lf\n", f[t][0][0]);
      return f[t][0][0];
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {5, -7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 1.5; verify_case(0, Arg2, findMaximum(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {5, -7, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 0.3333333333333333; verify_case(1, Arg2, findMaximum(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {1, 2, 2, 3, -10, 7}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; double Arg2 = 2.9166666666666665; verify_case(2, Arg2, findMaximum(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {-100, -100, -100, -100, -100, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = -66.66666666666667; verify_case(3, Arg2, findMaximum(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {869, 857, -938, -290, 79, -901, 32, -907, 256, -167, 510, -965, -826, 808, 890,
 -233, -881, 255, -709, 506, 334, -184, 726, -406, 204, -912, 325, -445, 440, -368}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; double Arg2 = 706.0369290573373; verify_case(4, Arg2, findMaximum(Arg0, Arg1)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        MergersDivTwo ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
