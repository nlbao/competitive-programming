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

const int MAX_N = 55;
vii a;
ll mask[MAX_N], g[MAX_N], id[MAX_N];
int sum[MAX_N];
int n, res, limit;


int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

void tryf(int i, int c, ll f, int value) {
    if (i >= n) {
        if (c == limit && f == g[0]) res = max(res,value);
        return;
    }

    if (c + n-i < limit) return;
    if (value + sum[i] <= res) return;
    if ((f|g[i]) != g[0]) return;

    cout <<  "  "  << i << "      " << f << "     " << value << "          " << g[0] << "     " << mask[i] << endl;

    if (c < limit) tryf(i+1, c+1, f|mask[i], value + sum[i]-sum[i+1]);
    tryf(i+1, c, f, value);
}


class MagicMoleculeEasy {
    public:
    int maxMagicPower(vector <int> power, vector <string> bond, int k) {
        n = size(power);
        limit = k;
        a.clear();
        rep(i,n) a.pb(mp(power[i],i));
        //sort(all(a));
        rep(i,n) id[a[i].sc] = i;
        rep(i,n) id[i] = i;
        rep(i,n) {
            ll x = 1LL<<id[i];
            rep(j,n)
                if (bond[i][j] == 'Y')
                    x |= 1LL<<id[j];
            mask[id[i]] = x;
        }
        fill(sum,0);
        fill(g,0);
        ford(i,n-1,0) {
            sum[i] = sum[i+1] + power[id[i]];
            g[i] = g[i+1]|mask[i];
        }

        res = -1;
        rep(i,n) tryf(i,0,0,0);
        return res;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NY",
 "YN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 2; verify_case(0, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(1, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {100, 1, 100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYN",
 "YNY",
 "NYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 200; verify_case(2, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {4, 7, 5, 8}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNY",
 "YNYN",
 "NYNY",
 "YNYN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 2; int Arg3 = 15; verify_case(3, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {46474, 60848, 98282, 58073, 42670, 50373}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NYNNNY", "YNNYNY", "NNNYYY", "NYYNNN", "NNYNNN", "YYYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 209503; verify_case(4, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNYYYNYYNYNNY", "NNYNYYYYYYYNY", "YYNYYNYYYYYYY", "YNYNYYNYYYYYY",
 "YYYYNNYYYYYNY", "NYNYNNYYYYYNN", "YYYNYYNYYYYYY", "YYYYYYYNYNYYY",
 "NYYYYYYYNYYYY", "YYYYYYYNYNNNN", "NYYYYYYYYNNYN", "NNYYNNYYYNYNN", "YYYYYNYYYNNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 9; int Arg3 = -1; verify_case(5, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_6() { int Arr0[] = {1, 1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NN", "NN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1; int Arg3 = 1; verify_case(6, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }
	void test_case_7() { int Arr0[] = {1,1,2,5,2,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"NNNNNNN","NNYNNNN","NYNNNYN","NNNNNNY","NNNNNNN","NNYNNNN","NNNYNNN"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 3; int Arg3 = 11; verify_case(7, Arg3, maxMagicPower(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

// BEGIN CUT HERE
    int main() {
        MagicMoleculeEasy ___test;
        ___test.run_test(5);
    }
// END CUT HERE
