#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector< pair<int, int> > vii;
template<class T> inline int size(const T&c) { return c.size(); }

#define foru(i,a,b) for(int i = int(a); i <= int(b); ++i)
#define ford(i,b,a) for(int i = int(b); i >= int(a); --i)
#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(a) a.begin(),a.end()
#define size(a) int(a.size())
#define fill(a,x) memset(a, (x), sizeof(a))
#define mp(x,y) make_pair((x), (y))
#define pb(x) push_back((x))
#define fr first
#define sc second

int a[33], b[33];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

class NextOrPrev {
    public:
    int getMinimum(int nextCost, int prevCost, string s1, string s2) {
        int n = size(s1), res = 0;
        rep(i,n) {
            a[i] = s1[i];
            b[i] = s2[i];
        }

        for(int turn = 0; turn < 26*26*26; ++turn) {
            int x = -1;
            rep(i,n)
                if (a[i] < b[i])
                    if (x < 0 || a[i] > a[x]) x = i;
            if (x < 0) break;
            int tmp = a[x];
            rep(i,n)
                if (a[i] == tmp) {
                    ++a[i];
                    res += nextCost;
                }
        }

        for(int turn = 0; turn < 26*26*26; ++turn) {
            int x = -1;
            rep(i,n)
                if (a[i] > b[i])
                    if (x < 0 || a[i] < a[x]) x = i;
            if (x < 0) break;
            int tmp = a[x];
            rep(i,n)
                if (a[i] == tmp) {
                    --a[i];
                    res += prevCost;
                }
        }

        rep(i,n) if (a[i] != b[i]) return -1;
        return res;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 8; string Arg2 = "ae"; string Arg3 = "bc"; int Arg4 = 21; verify_case(0, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 5; int Arg1 = 8; string Arg2 = "ae"; string Arg3 = "cb"; int Arg4 = -1; verify_case(1, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 1; string Arg2 = "srm"; string Arg3 = "srm"; int Arg4 = 0; verify_case(2, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 10; int Arg1 = 1; string Arg2 = "acb"; string Arg3 = "bdc"; int Arg4 = 30; verify_case(3, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_4() { int Arg0 = 10; int Arg1 = 1; string Arg2 = "zyxw"; string Arg3 = "vuts"; int Arg4 = 16; verify_case(4, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_5() { int Arg0 = 563; int Arg1 = 440; string Arg2 = "ptrbgcnlaizo"; string Arg3 = "rtscedkiahul"; int Arg4 = 10295; verify_case(5, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_6() { int Arg0 = 126; int Arg1 = 311; string Arg2 = "yovlkwpjgsna"; string Arg3 = "zpwnkytjisob"; int Arg4 = -1; verify_case(6, Arg4, getMinimum(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};

// BEGIN CUT HERE
    int main() {
        NextOrPrev ___test;
        ___test.run_test(-1);
    }
// END CUT HERE
