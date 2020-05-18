#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }


const int MAX_N = 55;

int n, limit;
int s[MAX_N][MAX_N][3];


int getS(int x0, int y0, int x1, int y1, int types) {
	return s[x1][y1][types] - s[x0-1][y1][types] - s[x1][y0-1][types] + s[x0-1][y0-1][types];
}


int check(int x0, int y0, int x1, int y1, int types) {
	int sum = getS(x0, y0, x1, y1, types);
	int area = (x1-x0+1)*(y1-y0+1);
	int need = area - sum;
	int remain = s[n][n][types] - sum;

	if (need == 0) return area;
	if (remain < need || s[n][n][0] == 0)
		return -1;
	int cost = 0;
	int t = getS(x0, y0, x1, y1, 0);
	if (types == 0) cost = need;
	else cost = 2*(need-t) + t;
	if (cost > limit)
		return -1;
	return area;
}


class ApplesAndPears {
public:
	int getArea(vector <string> board, int K) {
		fill(s, 0);
		n = board.size();
		limit = K;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) {
				int x = i+1, y = j+1;
				if (board[i][j] == '.') s[x][y][0] = 1;
				else if (board[i][j] == 'A') s[x][y][1] = 1;
				else s[x][y][2] = 1;
			}
		// calculate s
		for (int i = 2; i <= n; ++i) for (int j = 0; j < 3; ++j) {
			s[1][i][j] += s[1][i-1][j];
			s[i][1][j] += s[i-1][1][j];
		}
		for (int i = 2; i <= n; ++i)
			for (int j = 2; j <= n; ++j)
				for (int x = 0; x < 3; ++x)
					s[i][j][x] += s[i-1][j][x] + s[i][j-1][x] - s[i-1][j-1][x];
		// calculate result
		int res = 1;
		for (int x0 = 1; x0 <= n; ++x0)
			for (int y0 = 1; y0 <= n; ++y0)
				for (int x1 = x0; x1 <= n; ++x1)
					for (int y1 = y0; y1 <= n; ++y1)
						for (int types = 0; types < 3; ++types)
							res = max(res, check(x0, y0, x1, y1, types));
		return res;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {".A",
 "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; int Arg2 = 1; verify_case(0, Arg2, getArea(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {".A",
 "P."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(1, Arg2, getArea(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {".PP",
 "PPA",
 "PAP"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 6; verify_case(2, Arg2, getArea(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"A.P.PAAPPA",
 "PPP..P.PPP",
 "AAP.A.PAPA",
 "P.PA.AAA.A",
 "...PA.P.PA",
 "P..A.A.P..",
 "PAAP..A.A.",
 "PAAPPA.APA",
 ".P.AP.P.AA",
 "..APAPAA.."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; int Arg2 = 21; verify_case(3, Arg2, getArea(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
    int main() {
        ApplesAndPears ___test;
        ___test.run_test(-1);
       int X ;
       scanf("%d",&X) ;
    }
// END CUT HERE
