#include <cstdio>
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
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, container) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 55;


bool a[MAX_N][MAX_N];
bool okleft[MAX_N], okright[MAX_N], oktop[MAX_N], okbot[MAX_N];


class BoardFoldingDiv2 {
public:
	int howMany(vector <string> paper) {
		int n = paper.size(), m = paper[0].size();
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				a[i][j] = paper[i-1][j-1] == '1';
		// init
			// left
		filla(okleft, false);
		okleft[0] = true;
		for (int i = 1; i < m; ++i)
			for (int x = i; x >= 1; --x) {
				int y = i + (i-x+1);
				if (y > m) break;
				bool ok = true;
				for (int k = 1; k <= n; ++k)
					if (a[k][x] != a[k][y]) {
						ok = false;
						break;
					}
				if (!ok) break;
				if (okleft[x-1]) {
					okleft[i] = true;
					break;
				}
			}
			// right
		filla(okright, false);
		okright[m+1] = true;
		for (int i = m; i > 1; --i)
			for (int x = i; x <= m; ++x) {
				int y = i - (x-i+1);
				if (y < 1) break;
				bool ok = true;
				for (int k = 1; k <= n; ++k)
					if (a[k][x] != a[k][y]) {
						ok = false;
						break;
					}
				if (!ok) break;
				if (okright[x+1]) {
					okright[i] = true;
					break;
				}
			}
			// top
		filla(oktop, false);
		oktop[0] = true;
		for (int i = 1; i < n; ++i)
			for (int x = i; x >= 1; --x) {
				int y = i + (i-x+1);
				if (y > n) break;
				bool ok = true;
				for (int k = 1; k <= m; ++k)
					if (a[x][k] != a[y][k]) {
						ok = false;
						break;
					}
				if (!ok) break;
				if (oktop[x-1]) {
					oktop[i] = true;
					break;
				}
			}
			// bot
		filla(okbot, false);
		okbot[n+1] = true;
		for (int i = n; i > 1; --i)
			for (int x = i; x <= n; ++x) {
				int y = i - (x-i+1);
				if (y < 1) break;
				bool ok = true;
				for (int k = 1; k <= m; ++k)
					if (a[x][k] != a[y][k]) {
						ok = false;
						break;
					}
				if (!ok) break;
				if (okbot[x+1]) {
					okbot[i] = true;
					break;
				}
			}
		// cal
		int ans = 0;
		for (int i = 1; i <= m; ++i) if (okleft[i-1])
			for (int j = 1; j <= n; ++j) if (oktop[j-1])
				for (int x = i; x <= m; ++x) if (okright[x+1])
					for (int y = j; y <= n; ++y) if (okbot[y+1])
						++ans;
		return ans;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6();}
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"10", "11"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(0, Arg1, howMany(Arg0)); }
	void test_case_1() { string Arr0[] = {"1111111","1111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 84; verify_case(1, Arg1, howMany(Arg0)); }
	void test_case_2() { string Arr0[] = {"0110","1001","1001", "0110"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 9; verify_case(2, Arg1, howMany(Arg0)); }
	void test_case_3() { string Arr0[] = {"0", "0", "0", "1", "0", "0"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(3, Arg1, howMany(Arg0)); }
	void test_case_4() { string Arr0[] = {"000", "010", "000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(4, Arg1, howMany(Arg0)); }
	void test_case_5() { string Arr0[] = {"11111100111111111111111111111111111111111111111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 300; verify_case(5, Arg1, howMany(Arg0)); }
	void test_case_6() { string Arr0[] = {"000", "011", "011"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(6, Arg1, howMany(Arg0)); }

// END CUT HERE

};
 
// BEGIN CUT HERE
int main() {
	BoardFoldingDiv2 ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
