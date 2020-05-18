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

const int MAX_N = 55;

int num(char x) {
   if (x == 'R') return 0;
   if (x == 'G') return 1;
   if (x == 'B') return 2;
   if (x == '*') return 3;
}

class Stamp {
   public:
   int getMinimumCost(string a, int stampCost, int pushCost) {
      int n = size(a);
      int color[MAX_N][MAX_N];
      fill(color,0);
      foru(i,1,n) {
         bool c[4];
         fill(c,0);
         foru(j,i,n) {
            c[num(a[j-1])] = true;
            int t = c[0]+c[1]+c[2];
            if (t > 1) break;
            ford(k,3,0)
               if (c[k]) color[i][j] = k+1;
         }
      }

      ll f[MAX_N][MAX_N];
      foru(i,0,n) f[0][i] = i*stampCost;
      foru(i,1,n)
         foru(j,1,n) {
            f[i][j] = 1000000000000000000LL;
            if (j <= i && color[i-j+1][i] > 0)
               foru(k,i-j,i-1) {
                  int l = k-j+1, r = k;
                  if (l < 1) {
                     l = 1;
                     r = l+j-1;
                  }
                  if (k == i-j) f[i][j] = min(f[i][j],f[k][j] + ll(pushCost));
                  else if (color[i-j+1][i] == 4 || color[l][r] == 4 || color[i-j+1][i] == color[l][r])
                     f[i][j] = min(f[i][j],f[r][j] + ll(pushCost));
               }
         }

      ll res = f[n][1];
      foru(j,2,n) res = min(res,f[n][j]);
      return res;
   }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "RRGGBB"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(0, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arg0 = "R**GB*"; int Arg1 = 1; int Arg2 = 1; int Arg3 = 5; verify_case(1, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arg0 = "BRRB"; int Arg1 = 2; int Arg2 = 7; int Arg3 = 30; verify_case(2, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arg0 = "R*RR*GG"; int Arg1 = 10; int Arg2 = 58; int Arg3 = 204; verify_case(3, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arg0 = "*B**B**B*BB*G*BBB**B**B*"; int Arg1 = 5; int Arg2 = 2; int Arg3 = 33; verify_case(4, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arg0 = "*R*RG*G*GR*RGG*G*GGR***RR*GG"; int Arg1 = 7; int Arg2 = 1; int Arg3 = 30; verify_case(5, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }
	void test_case_6() { string Arg0 = "RR*GG"; int Arg1 = 1; int Arg2 = 100000; int Arg3 = 300002; verify_case(6, Arg3, getMinimumCost(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

 // BEGIN CUT HERE
    int main()
        {
        Stamp ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
