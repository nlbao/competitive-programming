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

int vc(char ch) {
   if (ch == '.') return 0;
   return int(ch)-int('0');
}

int vs(string s) {
   int v = 0;
   fab(i, 0, 2)
      v += vc(s[i]);
   return v;
}

bool ok(string s1, string s2) {
   if ((s1[2] != '.') && (s2[0] != '.')) return true;
   return false;
}

class DengklekMakingChains {
   public:
   int maxBeauty(vector <string> chains) {
      int n = chains.size(), a = 0, b = 0, c = 0, res = 0;
      fab(i, 0, n-1) {
         string s = chains[i];
         int v = vs(s);
         if (s[1] != '.') res = max(res, v);
         else {
            res = max(res, vc(s[0]));
            res = max(res, vc(s[2]));
         }
         if (s[1] != '.')
            if ((s[0] != '.') && (s[2] != '.')) b += v;
            else
               if (s[2] != '.') a = max(a, v);
               else if (s[0] != '.') c = max(c, v);
      }
      res = max(res, a+b+c);
      fab(i, 0, n-1) {
         string s = chains[i];
         if (s[1] == '.') {
            res = max(res, a+b+vc(s[0]));
            res = max(res, vc(s[2])+b+c);
         }
      }
      fab(i, 0, n-1)
         fab(j, i+1, n-1) {
            string s1 = chains[i], s2 = chains[j];
            if ((s1[1] == '.') && (s2[1] == '.')) {
               res = max(res, b+vc(s1[2])+vc(s2[0]));
               res = max(res, b+vc(s2[2])+vc(s1[0]));
            }
         }
      return res;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".15", "7..", "402", "..3"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 19; verify_case(0, Arg1, maxBeauty(Arg0)); }
	void test_case_1() { string Arr0[] = {"..1", "7..", "567", "24.", "8..", "234"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 36; verify_case(1, Arg1, maxBeauty(Arg0)); }
	void test_case_2() { string Arr0[] = {"...", "..."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(2, Arg1, maxBeauty(Arg0)); }
	void test_case_3() { string Arr0[] = {"16.", "9.8", ".24", "52.", "3.1", "532", "4.4", "111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 28; verify_case(3, Arg1, maxBeauty(Arg0)); }
	void test_case_4() { string Arr0[] = {"..1", "3..", "2..", ".7."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, maxBeauty(Arg0)); }
	void test_case_5() { string Arr0[] = {"412", "..7", ".58", "7.8", "32.", "6..", "351", "3.9", "985", "...", ".46"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 58; verify_case(5, Arg1, maxBeauty(Arg0)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        DengklekMakingChains ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
