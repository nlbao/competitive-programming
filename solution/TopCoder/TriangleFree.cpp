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

const int MAX_N = 62;

int n;
bool e[MAX_N][MAX_N];
bool isTriangle[MAX_N][MAX_N][MAX_N];
map<ll, ll> q;


ll solve(int u, ll mask) {
	cout << u << " " << mask << endl;
	if (mask == 0) return 1;
	if (u == n-1) return 2;
	if (q.find(mask) != q.end()) return q[mask];
	ll ans = 0;
	for (int v = u+1; v < n; ++v) {
		ll newMask = mask - (1<<u);
		for (int k = v+1; k < n; ++k)
			if ((newMask&(1<<k)) && isTriangle[u][v][k])
				newMask -= (1<<k);
		// cout << "		" << u << " " << v << ": " << mask << " " << newMask << endl;
		ans += solve(v, newMask);
		mask -= (1<<v);
	}
	return q[mask] = ans;
}


class TriangleFree {
public:
	long long count(int N, vector <int> x, vector <int> y) {
		n = N;
		int m = x.size();
		filla(e, 0);
		for (int i = 0; i < m; ++i)
			e[x[i]][y[i]] = e[y[i]][x[i]] = 1;
		filla(isTriangle, 0);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j) if (j != i)
				for (int k = 0; k < n; ++k) if (k != i && k != j)
					if (e[i][j] && e[j][k] && e[k][i]) {
						cout << "!!! " << i << " " << j << " " << k << endl;
						isTriangle[i][j][k] = 1;
					}
		ll ans = 0, mask = (1<<n)-1;
		q.clear();
		for (int i = 0; i < n; ++i) {
			ll t = solve(i, mask);
			ans += t;
			mask -= (1<<i);
		}
		return ans;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arr1[] = {0,1,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,0,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 14LL; verify_case(0, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 5; int Arr1[] = {0,0,0,0,1,1,1,2,2,3}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,3,4,2,3,4,3,4,4}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 16LL; verify_case(1, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 6; int Arr1[] = {0,0,1,1,1,3,1,2,2,4}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,2,3,4,4,5,4,5,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 40LL; verify_case(2, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 60; int Arr1[] = {10,20,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {20,30,10}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1008806316530991104LL; verify_case(3, Arg3, count(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arg0 = 60; int Arr1[] = {0,0,1,0,0,3,0,0,5,0,0,7,0,0,9,0,0,11,0,0,13,0,0,15,0,0,17,0,0,19,0,0,21,0,0,23,0,0,25,0,0,27,0,0,29,5,2,23,5,20,27,26,22,19,18,13,15,12,7,9}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arr2[] = {1,2,2,3,4,4,5,6,6,7,8,8,9,10,10,11,12,12,13,14,14,15,16,16,17,18,18,19,20,20,21,22,22,23,24,24,25,26,26,27,28,28,29,30,30,1,12,27,22,1,14,5,27,27,15,15,29,7,6,3}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 578333426763956224LL; verify_case(4, Arg3, count(Arg0, Arg1, Arg2)); }

// END CUT HERE

};
 
// BEGIN CUT HERE
int main() {
	TriangleFree ___test;
	// ___test.run_test(-1);
	___test.run_test(0);
	cin.get();
}
// END CUT HERE
