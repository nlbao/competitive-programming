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

const int MAX_N = 55;

string a1, b1, a2, b2;
vector<int> d;
double p[MAX_N];


// probability that i-th gene is a dominant gene
double cal(int i) {
	if (p[i] >= 0)
		return p[i];
	int c1 = 0, c2 = 0;
	if (isupper(a1[i])) ++c1;
	if (isupper(b1[i])) ++c1;
	if (isupper(a2[i])) ++c2;
	if (isupper(b2[i])) ++c2;
	if (c1 > c2) swap(c1, c2);
	double t = 0;
	if (c2 == 2) t = 1;
	else if (c2 == 0) t = 0;
	else if (c1 == 1 && c2 == 1) t = 0.75;
	else t = 0.5;	//c1 == 0 && c2 == 1
	if (d[i] != -1) t *= cal(d[i]);
	return p[i] = t;
}


class GeneticCrossover {
public:
	double cross(string p1a, string p1b, string p2a, string p2b,
		vector <int> dom, vector <int> rec, vector <int> dependencies) {
		a1 = p1a, b1 = p1b;
		a2 = p2a, b2 = p2b;
		d = dependencies;
		int n = dom.size();
		for (int i = 0; i < n; ++i) p[i] = -1;
		for (int i = 0; i < n; ++i)
			if (p[i] < 0)
				cal(i);
		double ans = 0;
		for (int i = 0; i < n; ++i)
			ans += p[i] * dom[i] + (1-p[i]) * rec[i];
		return ans;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "AaaAA"; string Arg1 = "AaaAA"; string Arg2 = "AaaAA"; string Arg3 = "AaaAA"; int Arr4[] = {1,2,3,4,5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {-1,-2,-3,-4,-5}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {-1,-1,-1,-1,1}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); double Arg7 = -5.0; verify_case(0, Arg7, cross(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_1() { string Arg0 = "AbegG"; string Arg1 = "ABEgG"; string Arg2 = "aBEgg"; string Arg3 = "abegG"; int Arr4[] = {5,5,5,5,5}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {1,1,1,1,1}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {-1,0,1,2,3}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); double Arg7 = 14.25; verify_case(1, Arg7, cross(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_2() { string Arg0 = "XyMpdnVsbinDvqBpcWGDLfsmQtZpeirvTmoRmBASfqqrFS"; string Arg1 = "xYmpdnVsBINdvQBPCwgDlFSmQTzpEIrVtmoRmbaSfqQRfS"; string Arg2 = "XYMpdnvsBINdVQbpCWgDlfSMqTzPeIrVTMOrmbaSfQqrFs"; string Arg3 = "XYMpDnVSBIndvQBPCWGDlFsMqtzpEiRVTMORMBASFqQrfS"; int Arr4[] = {-82,-35,-51,52,87,25,8,27,-12,-10,-63,-36,-95,-35,-98,95,-76,7,36,-35,92,23,-94,
 -31,-30,36,51,-49,-19,-3,19,32,58,82,-36,-87,-54,-17,-40,32,-91,-56,0,-16,70,42}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {-36,77,90,50,83,66,-94,-66,-22,-83,-86,-89,-55,-3,-51,18,-41,-91,91,32,-25,-60,
 5,79,100,85,60,98,55,95,-67,-46,-26,48,-64,16,-36,-95,-54,19,96,79,78,-91,-12,35}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {-1,-1,1,-1,3,-1,-1,1,3,5,4,0,-1,-1,2,8,5,4,-1,10,11,14,3,-1,
15,-1,7,-1,8,-1,-1,15,-1,-1,30,-1,26,26,-1,-1,-1,-1,-1,31,0,3}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); double Arg7 = -356.875; verify_case(2, Arg7, cross(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }
	void test_case_3() { string Arg0 = "fOai"; string Arg1 = "Foai"; string Arg2 = "fOAI"; string Arg3 = "FOAi"; int Arr4[] = {96,21,-34,-81}; vector <int> Arg4(Arr4, Arr4 + (sizeof(Arr4) / sizeof(Arr4[0]))); int Arr5[] = {77,-2,20,25}; vector <int> Arg5(Arr5, Arr5 + (sizeof(Arr5) / sizeof(Arr5[0]))); int Arr6[] = {-1,0,-1,-1}; vector <int> Arg6(Arr6, Arr6 + (sizeof(Arr6) / sizeof(Arr6[0]))); double Arg7 = 44.5; verify_case(3, Arg7, cross(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	GeneticCrossover ___test;
	___test.run_test(-1);
	cin.get();
}
// END CUT HERE
