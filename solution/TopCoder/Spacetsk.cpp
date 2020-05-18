#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PI;

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

const int MAX_L = 2007;

const ll MODUN = 1000000007;

int c[MAX_L][MAX_L];

int gcd(int x, int y) {
   if (!x || !y) return x+y;
   return (gcd(y,x%y));
}

ll cal(int x, int y, int k) {
   int n = gcd(x,y)+1;
   //if (k <= 10) cout << "             " << n << " " << k << " " << c[n][k] << endl;
   if (n < k) return 0;
   return c[n][k];
}

class Spacetsk {
   public:
   int countsets(int L, int H, int K) {
//call c
      int m = MAX_L-1;
      fill(c,0);
      c[1][0] = c[1][1] = 1;
      foru(i,2,m) {
         c[i][0] = c[i][i] = 1;
         foru(j,1,i-1) c[i][j] = (c[i-1][j]+c[i-1][j-1])%MODUN;
      }

      if (K == 1) return (L+1)*(H+1);

//solve
      ll res = 0;
      foru(i,0,L) {
         foru(a,-H,H) {
            if (a == 0) continue;
            int x = -MODUN;
            foru(j,0-i,L-i) {
               if (j == 0) continue;
               int t = a*j;
               if (t >= 0 && t <= H && (x == -MODUN || t > a*x)) x = j;
            }
            if (x > -MODUN) {
               res = (res+cal(abs(x),abs(a*x),K))%MODUN;
               //if (L <= 10) cout << i << " " << a << " " << x << " " << a*x << endl;
            }


            x = -MODUN;
            foru(j,0-i,L-i) {
               if (j == 0 || abs(j)%a != 0) continue;
               int t = j/a;
               if (t >= 0 && t <= H && (x == -MODUN || t > x/a)) x = j;
            }
            if (abs(a) > 1 && x > -MODUN) {
               res = (res+cal(abs(x),abs(x/a),K))%MODUN;
               //if (L <= 10) cout << i << " 1/" << a << " " << x << " " << x/a << endl;
            }
         }
         res = (res+cal(0,H,K))%MODUN;
      }
      return res;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; int Arg3 = 4; verify_case(0, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 1; int Arg3 = 4; verify_case(1, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 1; int Arg3 = 9; verify_case(2, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 2; int Arg1 = 2; int Arg2 = 2; int Arg3 = 23; verify_case(3, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 5; int Arg1 = 5; int Arg2 = 3; int Arg3 = 202; verify_case(4, Arg3, countsets(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arg0 = 561; int Arg1 = 394; int Arg2 = 20; int Arg3 = 786097180; verify_case(5, Arg3, countsets(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

 // BEGIN CUT HERE
int main() {
        Spacetsk ___test;
   ___test.run_test(-1);
}
// END CUT HERE
