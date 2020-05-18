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



class KingXNewBaby {
   public:
   string isValid(string s) {
      int n = s.size();
      cout << n << endl;
      if (n != 8) return "NO";
      int c = 0;
      char x, y;
      fab(i, 0, n-1)
         if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            ++c;
            if (c > 2) return "NO";
            if (c == 1) x = s[i];
            else {
               y = s[i];
               if (x != y) return "NO";
            }
         }
      if (c < 2) return "NO";
      return "YES";
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "dengklek"; string Arg1 = "YES"; verify_case(0, Arg1, isValid(Arg0)); }
	void test_case_1() { string Arg0 = "gofushar"; string Arg1 = "NO"; verify_case(1, Arg1, isValid(Arg0)); }
	void test_case_2() { string Arg0 = "dolphinigle"; string Arg1 = "NO"; verify_case(2, Arg1, isValid(Arg0)); }
	void test_case_3() { string Arg0 = "mystictc"; string Arg1 = "NO"; verify_case(3, Arg1, isValid(Arg0)); }
	void test_case_4() { string Arg0 = "rngringo"; string Arg1 = "NO"; verify_case(4, Arg1, isValid(Arg0)); }
	void test_case_5() { string Arg0 = "misof"; string Arg1 = "NO"; verify_case(5, Arg1, isValid(Arg0)); }
	void test_case_6() { string Arg0 = "metelsky"; string Arg1 = "YES"; verify_case(6, Arg1, isValid(Arg0)); }

// END CUT HERE

};

 // BEGIN CUT HERE
   int main()
        {
        KingXNewBaby ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
