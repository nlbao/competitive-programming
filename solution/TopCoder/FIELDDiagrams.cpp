#include <iostream>
#include <sstream>
#include <vector>

using namespace std ; 

typedef long long ll;

const int MAX_K = 40;

class FIELDDiagrams {
    public:
    ll countDiagrams(int fieldOrder) {
        ll f[MAX_K][MAX_K];
        ll res=0;
        for (int i=1; i <= fieldOrder; ++i) res+=f[1][i]=1;
        for (int i=2; i <= fieldOrder; ++i)
            for (int j=1; j <= fieldOrder-i+1; ++j) {
                f[i][j]=0;
                for (int k=j; k <= fieldOrder-i+2; ++k) f[i][j]+=f[i-1][k];
                res+=f[i][j];
            }
        return res;   
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 4LL; verify_case(0, Arg1, countDiagrams(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 13LL; verify_case(1, Arg1, countDiagrams(Arg0)); }
	void test_case_2() { int Arg0 = 5; long long Arg1 = 131LL; verify_case(2, Arg1, countDiagrams(Arg0)); }

// END CUT HERE

};
 
 // BEGIN CUT HERE 
    int main()
        {
        FIELDDiagrams ___test; 
        ___test.run_test(-1); 
       int X ;
       scanf("%d",&X) ;
        } 
    // END CUT HERE 
