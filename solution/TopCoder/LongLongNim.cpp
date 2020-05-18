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

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = 22;
const int MAX_M = 22;
const int MAX_P = 1<<MAX_N;

bool ok[MAX_N], win[MAX_N+4];
int pNext[MAX_P];
int pos[MAX_P], sum[MAX_P];


class LongLongNim {
public:
	int numberOfWins(int maxN, vector <int> moves) {
		sort(moves.begin(), moves.end());
		int nMoves = (int)moves.size();
		int n = moves[nMoves-1];
		fill(ok, false);
		for (int i = 0; i < nMoves; ++i)
			ok[n-moves[i]] = true;

		int res = maxN;
		fill(win, false);
		for (int x = 1; x <= min(n, maxN); ++x)
			for (int i = 0; i < nMoves; ++i)
				if (x >= moves[i] && !win[x-moves[i]]) {
					win[x] = true;
					--res;
					break;
				}
		if (maxN <= n) return res;

		maxN -= n;

		int m = 1<<n, nth = 1<<(n-1);
		for (int mask = 0; mask < m; ++mask) {
			bool toWin = false;
			for (int i = 0; i < n; ++i)
				if (!(mask&(1<<i)) && ok[i]) {
					toWin = true;
					break;
				}
			pNext[mask] = mask>>1;
			if (toWin)
				pNext[mask] |= nth;
		}

		int start = 0;
		for (int i = 0; i < n; ++i)
			if (win[i+1])
				start |= (1<<i);

		int len = 0, end = -1, cWin = 0;
		for (int i = 0; i < m; ++i) pos[i] = -1;
		pos[start] = 0;
		for (int x = pNext[start]; ; x = pNext[x]) {
			++len;
			--maxN;
			end = x;
			if ((x&nth) > 0) {
				--res;
				++cWin;
			}
			if (pos[x] == -1) {
				pos[x] = len;
				sum[x] = cWin;
			}
			else {
				len -= pos[x];
				cWin -= sum[x];
				break;
			}
		}

		int d = maxN / len, r = maxN % len;
		res -= d*cWin;
		for (int x = pNext[end], i = 0; i < r; x = pNext[x], ++i)
			res -= (x&nth) > 0;
		return res;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 20; int Arr1[] = {1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 5; verify_case(0, Arg2, numberOfWins(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 999; int Arr1[] = {1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 499; verify_case(1, Arg2, numberOfWins(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 1000000000; int Arr1[] = {1,2}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 333333333; verify_case(2, Arg2, numberOfWins(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 6543; int Arr1[] = {2,4,7,11,20}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1637; verify_case(3, Arg2, numberOfWins(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	LongLongNim ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
