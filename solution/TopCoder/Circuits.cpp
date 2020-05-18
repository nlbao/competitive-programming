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

int n;
bool avail[MAX_N];
int degI[MAX_N], f[MAX_N];
int w[MAX_N][MAX_N];

vector<int> parse(string s) {
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

int dfs(int u) {
   if (!avail[u]) return f[u];
   avail[u] = false;
   f[u] = 0;
   fab(i, 0, n-1)
      if (w[u][i] > 0)
         f[u] = max(f[u], w[u][i]+dfs(i));
   return f[u];
}

class Circuits {
   public:
   int howLong(vector <string> c, vector <string> t) {
      fill(w, 0);
      fill(degI, 0);
      n = c.size();
      fab(i, 0, n-1) {
         vector<int> v = parse(c[i]);
         vector<int> a = parse(t[i]);
         fab(j, 0, int(v.size())-1) {
            w[i][v[j]] = a[j];
            ++degI[v[j]];
         }
      }
      int res = 0;
      fill(avail, true);
      fab(i, 0, n-1)
         if (degI[i] == 0)
            res = max(res, dfs(i));
      return res;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 2",
 "2",
 ""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 3",
 "7",
 ""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; verify_case(0, Arg2, howLong(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1 2 3 4 5","2 3 4 5","3 4 5","4 5","5",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 2 2 2 2","2 2 2 2","2 2 2","2 2","2",""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; verify_case(1, Arg2, howLong(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1","2","3","","5","6","7",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2","2","2","","3","3","3",""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(2, Arg2, howLong(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"","2 3 5","4 5","5 6","7","7 8","8 9","10",
 "10 11 12","11","12","12",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"","3 2 9","2 4","6 9","3","1 2","1 2","5",
 "5 6 9","2","5","3",""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 22; verify_case(3, Arg2, howLong(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"","2 3","3 4 5","4 6","5 6","7","5 7",""}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"","30 50","19 6 40","12 10","35 23","8","11 20",""}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 105; verify_case(4, Arg2, howLong(Arg0, Arg1)); }

// END CUT HERE

};

 // BEGIN CUT HERE
    int main()
        {
        Circuits ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
