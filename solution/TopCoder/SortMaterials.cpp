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

class SortMaterials {
   public:
   int totalVolume(vector <string> data, vector <string> requirements) {
    
   }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"1 20 red", "2 30 blue", "10 1 green"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1009; verify_case(0, Arg2, totalVolume(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"1 20 red", "2 30 blue", "10 1 green"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"QUALITY=20"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; verify_case(1, Arg2, totalVolume(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"1 20 red", "2 30 blue", "10 1 green", "5 5 red", "5 6 red"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"COLOR=red", "EDGE=5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 250; verify_case(2, Arg2, totalVolume(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"1 20 red", "2 30 blue", "10 1 green", "5 5 red", "5 6 red"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"EDGE=1", "EDGE=5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(3, Arg2, totalVolume(Arg0, Arg1)); }

// END CUT HERE

};
 
 // BEGIN CUT HERE 
   int main()
        {
        SortMaterials ___test; 
        ___test.run_test(-1); 
        } 
    // END CUT HERE 
