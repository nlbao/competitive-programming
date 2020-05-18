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


const int MAX_N = 22;

int n, value;
int a[MAX_N], b[MAX_N], pos[MAX_N];
bool found, ok;

int cnt(int i) {
   int s = 0;
   foru(j,1,i-1)
      rep(k,b[j])
         if (pos[k] > j) ++s;
   s += ((n-i+1)*(n-i))/2;
   return s;
}

void tryf(int i) {
   if (i > 1 && cnt(i) < value) return;
   if (i > n) {
      found = true;
      return;
   }
   bool tmp = ok;
   int l = max(a[i],0);
   if (ok) l = 0;
   foru(j,l,n-1) if (pos[j] > n) {
      pos[j] = i;
      b[i] = j;
      if (j > a[i]) ok = true;
      tryf(i+1);
      if (found) return;
      ok = tmp;
      b[i] = -1;
      pos[j] = n+10;
   }
}


class StrIIRec {
   public:
   string recovstr(int nn, int minInv, string s) {
      n = nn;
      value = minInv;
      int m = s.size();
      foru(i,1,m) a[i] = s[i-1]-'a';
      foru(i,m+1,n) a[i] = -1;
      string res;
      found = false; ok = false;
      rep(i,n) pos[i] = n+10;
      tryf(1);

      if (n == 1) {
         if (b[1] < a[1]) found = false;
         if (minInv > 0) found = false;
      }

      if (found)
         rep(i, n) res += char(b[i+1]+int('a'));
      return res;
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; int Arg1 = 1; string Arg2 = "ab"; string Arg3 = "ba"; verify_case(0, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 9; int Arg1 = 1; string Arg2 = "efcdgab"; string Arg3 = "efcdgabhi"; verify_case(1, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 11; int Arg1 = 55; string Arg2 = "debgikjfc"; string Arg3 = "kjihgfedcba"; verify_case(2, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 15; int Arg1 = 0; string Arg2 = "e"; string Arg3 = "eabcdfghijklmno"; verify_case(3, Arg3, recovstr(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 9; int Arg1 = 20; string Arg2 = "fcdebiha"; string Arg3 = "fcdehigba"; verify_case(4, Arg3, recovstr(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

 // BEGIN CUT HERE
int main() {
        StrIIRec ___test;
   ___test.run_test(-1);
}
// END CUT HERE
