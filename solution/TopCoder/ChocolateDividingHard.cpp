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

const int MAX_N = 80;

int n, m, sum, ans;
vector<int> rows;
int w[MAX_N][MAX_N], a[5][MAX_N], s[5][MAX_N];


bool check(int value) {
	int x = 0, pre = -1;
	for (int k = 0; k < 4; ++k) {
		while (x < m) {
			bool ok = true;
			for (int id = 0; id < 4; ++id)
				if (s[id][x] - (pre >= 0 ? s[id][pre] : 0) < value) {
					ok = false;
					break;
				}
			if (ok) break;
			++x;
		}
		if (x >= m) return false;
		pre = x;
		++x;
	}
	return true;
}


int solve() {
	for (int id = 0; id < 4; ++id) {
		int x = id > 0 ? rows[id-1]+1 : 0;
		int y = rows[id];
		for (int i = 0; i < m; ++i) {
			a[id][i] = 0;
			for (int j = x; j <= y; ++j)
				a[id][i] += w[j][i];
			s[id][i] = a[id][i];
			if (i > 0) s[id][i] += s[id][i-1];
		}
	}

	int l = ans+1, r = sum;
	while (l <= r) {
		int mid = (l+r)>>1;
		if (check(mid)) {
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	return ans;
}


class ChocolateDividingHard {
public:
	int findBest(vector<string> chocolate) {
		n = (int)chocolate.size();
		m = chocolate[0].length();
		sum = 0;
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) {
				w[i][j] = chocolate[i][j] - '0';
				sum += w[i][j];
			}
		ans = 0;
		for (int x = 0; x < n-3; ++x)
			for (int y = x+1; y < n-2; ++y)
				for (int z = y+1; z < n-1; ++z) {
					rows.clear();
					rows.push_back(x);
					rows.push_back(y);
					rows.push_back(z);
					rows.push_back(n-1);
					solve();
				}
		return ans;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {
"95998",
"21945",
"23451",
"99798",
"74083"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(0, Arg1, findBest(Arg0)); }
	void test_case_1() { string Arr0[] = {
"12942",
"23456",
"99798",
"98998",
"67675"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; verify_case(1, Arg1, findBest(Arg0)); }
	void test_case_2() { string Arr0[] = {
"129420",
"234560",
"997980",
"989980",
"676760"
}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, findBest(Arg0)); }
	void test_case_3() { string Arr0[] = {"75356291270936062","61879202375922897","36129319478450361","06320615547656937","45254744307868843","14920689266495048","71727226106159490","91771159776736563","94812939088509638","56115984810304444","76317596217857418","59753883189643338"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 44; verify_case(3, Arg1, findBest(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	ChocolateDividingHard ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
