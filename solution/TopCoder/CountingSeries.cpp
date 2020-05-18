#include <iostream>
#include <sstream>
#include <vector>

using namespace std ; 

typedef long long ll;

class CountingSeries {
    public:
    ll countThem(ll a, ll b, ll c, ll d, ll upperBound) {        
        ll n = upperBound, res = 0;
        ll i = 0, j = (n-a)/b;
        if (j >= i) res = j-i+1;
        ll p = c;
        for (i = 0; p <= n; ++i) {
            ++res;
            if ((p-a >= 0) && ((p-a)%b == 0)) --res;
            p = p*d;
            if (d == 1) break;           
        }          
        return res;
    } 

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const ll &Expected, const ll &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { ll Arg0 = 1LL; ll Arg1 = 1LL; ll Arg2 = 1LL; ll Arg3 = 2LL; ll Arg4 = 1000LL; ll Arg5 = 1000LL; verify_case(0, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_1() { ll Arg0 = 3LL; ll Arg1 = 3LL; ll Arg2 = 1LL; ll Arg3 = 2LL; ll Arg4 = 1000LL; ll Arg5 = 343LL; verify_case(1, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_2() { ll Arg0 = 40LL; ll Arg1 = 77LL; ll Arg2 = 40LL; ll Arg3 = 100000LL; ll Arg4 = 40LL; ll Arg5 = 1LL; verify_case(2, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_3() { ll Arg0 = 452LL; ll Arg1 = 24LL; ll Arg2 = 4LL; ll Arg3 = 5LL; ll Arg4 = 600LL; ll Arg5 = 10LL; verify_case(3, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }
	void test_case_4() { ll Arg0 = 234LL; ll Arg1 = 24LL; ll Arg2 = 377LL; ll Arg3 = 1LL; ll Arg4 = 10000LL; ll Arg5 = 408LL; verify_case(4, Arg5, countThem(Arg0, Arg1, Arg2, Arg3, Arg4)); }

// END CUT HERE

};
 
 // BEGIN CUT HERE 
    int main()
        {
        CountingSeries ___test; 
        ___test.run_test(-1); 
       int X ;
       scanf("%d",&X) ;
        } 
    // END CUT HERE 
