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


const int MAX_N = 17;


int tmp[2*MAX_N], f[1<<MAX_N];


class AntlerSwapping {
public:
	int getmin(vector <int> a, vector <int> b, int limit) {
		int n = a.size(), nMask = 1<<n;
		f[0] = 0;
		for (int mask = 1; mask < nMask; ++mask) {
			int m = 0;
			for (int i = 0; i < n; ++i)
				if (mask&(1<<i)) {
					tmp[m++] = a[i];
					tmp[m++] = b[i];
				}
			sort(tmp, tmp+m);
			bool ok = true;
			for (int i = 0; i < m-1; i += 2)
				if (tmp[i+1]-tmp[i] > limit) {
					ok = false;
					break;
				}
			f[mask] = ok ? 1 : -1;

			int x = 0;
			do {
				int y = mask-x;
				if (f[x] > -1 && f[y] > -1)
					f[mask] = max(f[mask], f[x] + f[y]);
				x = (x+1+(~mask))&mask;
			} while (x != 0);
		}
		return f[nMask-1] == -1 ? -1 : n-f[nMask-1];
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3, 2, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 5, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; int Arg3 = 1; verify_case(0, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {4, 2, 6, 4, 8, 5, 2, 3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {3, 4, 5, 2, 8, 5, 7, 6}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(1, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {12, 34, 56, 78}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1234, 2345, 3456, 4567}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 100; int Arg3 = -1; verify_case(2, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {47, 58, 2013}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {49, 55, 2013}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 0; verify_case(3, Arg3, getmin(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {4, 1, 7, 5, 7, 8, 2, 1, 3, 1, 7, 5, 9, 4, 9, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10, 6, 5, 3, 1, 8, 4, 4, 4, 7, 1, 4, 6, 5, 10, 10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 7; verify_case(4, Arg3, getmin(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	AntlerSwapping ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
