#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }



string gen(int len, int l, int r, char background) {
	string s = "";
	for (int i = 0; i < l; ++i) s.push_back(background);
	s.push_back('X');
	for (int i = l+1; i < r; ++i) s.push_back(' ');
	if (l < r) s.push_back('X');
	for (int i = r; i < len-1; ++i) s.push_back(background);
	return s;
}


class DiamondLogo {
public:
	vector <string> logo(int size, char background) {
		int len = 2*size - 1;
		int l = size-1, r = l;
		vector<string> ans;
		for (int k = 0; k < size; ++k) {
			ans.push_back(gen(len, l, r, background));
			--l, ++r;
		}
		l = 0, r = len-1;
		for (int k = 0; k < size-1; ++k) {
			++l, --r;
			ans.push_back(gen(len, l, r, background));
		}
		return ans;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <string> &Expected, const vector <string> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { int Arg0 = 2; char Arg1 = '.'; string Arr2[] = { ".X.",  "X X",  ".X." }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(0, Arg2, logo(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 3; char Arg1 = '-'; string Arr2[] = { "--X--",  "-X X-",  "X   X",  "-X X-",  "--X--" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(1, Arg2, logo(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 5; char Arg1 = 'q'; string Arr2[] = { "qqqqXqqqq",  "qqqX Xqqq",  "qqX   Xqq",  "qX     Xq",  "X       X",  "qX     Xq",  "qqX   Xqq",  "qqqX Xqqq",  "qqqqXqqqq" }; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); verify_case(2, Arg2, logo(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	DiamondLogo ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
