#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define forI(i, a, b) for (int i = a; i <= b; ++i)
#define forD(i, a, b) for (int i = a; i >= b; --i)
#define ll long long

class MinskyMysteryDiv2 {
    public:
    long long computeAnswer(long long N) {
        ll f[5];
        f[0] = N;   f[1] = 1;
        f[2] = f[3] = f[4] = 0;
        while (1 > 0) {
            ++f[1];
            f[4] = 0;
            while (f[0] > 0) {
                if ((f[0] > 0) && (f[1] > 0)) {
                    int x = min(f[0], f[1]);
                    f[0] -= x;  f[1] -= x;
                    f[2] += x;  f[3] += x;
                }
                ++f[4];
                if ((f[0] == 0) && (f[1] == 0)) return(f[3]+f[4]);
                f[1] += f[3];   f[3] = 0;
            }
            f[0] += f[2];   f[2] = 0;
        }
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { long long Arg0 = 2LL; long long Arg1 = 3LL; verify_case(0, Arg1, computeAnswer(Arg0)); }
	void test_case_1() { long long Arg0 = 3LL; long long Arg1 = 4LL; verify_case(1, Arg1, computeAnswer(Arg0)); }
	void test_case_2() { long long Arg0 = 4LL; long long Arg1 = 4LL; verify_case(2, Arg1, computeAnswer(Arg0)); }
	void test_case_3() { long long Arg0 = 15LL; long long Arg1 = 8LL; verify_case(3, Arg1, computeAnswer(Arg0)); }
	void test_case_4() { long long Arg0 = 30LL; long long Arg1 = 14LL; verify_case(4, Arg1, computeAnswer(Arg0)); }

// END CUT HERE

};

 // BEGIN CUT HERE
    int main()
        {
        MinskyMysteryDiv2 ___test;
        ___test.run_test(-1);
       int X ;
       scanf("%d",&X) ;
        }
    // END CUT HERE
