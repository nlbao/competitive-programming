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

const int MAX_N = 100;

int c, res;
VI e[MAX_N];
int num[MAX_N], low[MAX_N];
bool ok[MAX_N];
VI stack, myCost;

void dfs(int u) {
   stack.pb(u);
   num[u] = ++c;
   low[u] = MAX_N;
   int v;
   fab(i, 0, int(e[u].size())-1) {
      v = e[u][i];
      if (ok[v])
         if (num[v] == 0) {
            dfs(v);
            low[u] = min(low[u], low[v]);
         }
         else low[u] = min(low[u], num[v]);
   }
   ok[u] = false;
   if (low[u] >= num[u]) {
      int minC = myCost[u];
      do {
         v = stack[stack.size()-1];
         stack.pop_back();
         minC = min(minC, myCost[v]);
      } while (v != u);
      res += minC;
   }
}

class Police {
   public:
   int minimalCost(vector <int> cost, vector <string> roads) {
      int n = cost.size();
      myCost = cost;
      fab(i, 0, n-1) e[i].clear();
      fab(i, 0, n-1)
         fab(j, 0, n-1)
            if (roads[i][j] == 'Y')
               e[i].pb(j);
      res = c = 0;
      fill(ok, true);
      fill(num, 0);
      fab(i, 0, n-1)
         if (ok[i]) dfs(i);
      return res;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNYY", "YNNNN", "NNNYN", "NNYNN", "NYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4; verify_case(0, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1000000,1000000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NY", "YN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1000000; verify_case(1, Arg2, minimalCost(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {5, 3, 10, 4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNN", "NNYN", "NNNY", "YNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; verify_case(2, Arg2, minimalCost(Arg0, Arg1)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        Police ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
