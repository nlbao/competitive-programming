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


const string dd = "NESW";
const int dx[4] = {+1, 0, -1, 0};
const int dy[4] = {0, +1, 0, -1};


std::vector<int> x, y;


class Surveyor {
public:
	int area(string dir, vector <int> length) {
		int m = dir.size();
		x.clear();
		y.clear();
		x.push_back(0);
		y.push_back(0);
		int u = 0, v = 0;
		for (int i = 0; i < m; ++i) {
			int k = 0;
			for (; k < 4; ++k)
				if (dd[k] == dir[i]) break;
			u += dx[k] * length[i];
			v += dy[k] * length[i];
			x.push_back(u);
			y.push_back(v);
		}
		int n = x.size()-1, ans = 0;
		for (int i = 0; i < n; ++i) {
			int j = (i-1+n) % n;
			ans += (x[j] + x[i]) * (y[j] - y[i]);
		}
		return abs(ans)/2;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "NWWSE"; int Arr1[] = {10,3,7,10,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; verify_case(0, Arg2, area(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "NESWNWSW"; int Arr1[] = {20,200,30,100,20,30,10,70}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 4700; verify_case(1, Arg2, area(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Surveyor ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
