#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-x))
#define fr first
#define sc second


const int MAX_N = 2e5 + 5e4 + 55;


int p[MAX_N];
map<int, int> q;


class BSTConstruction {
public:
	long long sumHeights(int n, int seed, int limit) {
		ll x = seed;
		for (int i = 0; i < n; ++i) {
			p[i] = i;
			x = (x * 295397169) % 1073741789;
			if ((x * 1000000) / 1073741789 < limit) {
				x = (x * 295397169) % 1073741789;
				int j = (x * (i + 1)) / 1073741789;
				swap(p[i], p[j]);
			}
		}

		ll ans = 0;
		q.clear();
		for (int i = 0; i < n; ++i) {
			int x = p[i], h = 1;
			if (!q.empty()) {
				map<int, int>::iterator it = q.lower_bound(x);
				if (it == q.begin()) {
					h = it->second+1;
				}
				else if (it == q.end()) {
					--it;
					h = it->second+1;
				}
				else {
					h = it->second+1;
					--it;
					h = max(h, it->second+1);
				}
			}
			q[x] = h;
			ans += h;
		}
		return ans;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 10; int Arg1 = 12345678; int Arg2 = 500000; long long Arg3 = 40LL; verify_case(0, Arg3, sumHeights(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 87654321; int Arg2 = 1000000; long long Arg3 = 31LL; verify_case(1, Arg3, sumHeights(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 10; int Arg1 = 45454545; int Arg2 = 0; long long Arg3 = 55LL; verify_case(2, Arg3, sumHeights(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 1; int Arg1 = 99988877; int Arg2 = 12345; long long Arg3 = 1LL; verify_case(3, Arg3, sumHeights(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	BSTConstruction ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
