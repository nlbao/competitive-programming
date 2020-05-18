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


int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

string cut(string s, int l, int r) {
    string t = "";
    foru(i,l,r) t = t + s[i];
    return t;
}

bool cmp(string a, string b) {
    int n = size(a), m = size(b);
    rep(i,min(n,m))
        if (a[i] > b[i]) return true;
        else if (a[i] < b[i]) return false;
    return n > m;
}


class TheLargestString {
    public:
    string find(string a, string b) {
        int n = size(a);
        string ra = "", rb = "";
        int i = 0;
        while (i < n) {
            int tmp = i;
            foru(j,i,n-1)
                if (a[j] > a[tmp]) tmp = j;
            ra += a[tmp];
            rb += b[tmp];
            i = tmp+1;
        }

        cout << a << endl << endl << ra << endl << rb << endl << endl;

        int m = size(ra);
        string res = ra+rb;
        rep(i,m)
            foru(j,i,m-1) {
                string tmp = cut(ra,i,j) + cut(rb,i,j);
                if (cmp(tmp,res)) res = tmp;
            }

        bool stop = false;
        while (!stop) {
            stop = true;
            int m = size(ra);
            rep(i,m) {
                string tmp = cut(ra,0,i) + cut(ra,i+2,m-1) + cut(rb,0,i) + cut(rb,i+2,m-1);
                if (cmp(tmp,res)) {
                    res = tmp;
                    stop = false;
                    ra = cut(ra,0,i) + cut(ra,i+2,m-1);
                    rb = cut(rb,0,i) + cut(rb,i+2,m-1);
                    break;
                }
            }
        }
        return res;
    }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "ab"; string Arg1 = "zy"; string Arg2 = "by"; verify_case(0, Arg2, find(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "abacaba"; string Arg1 = "zzzaaaa"; string Arg2 = "cbaaaa"; verify_case(1, Arg2, find(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "x"; string Arg1 = "x"; string Arg2 = "xx"; verify_case(2, Arg2, find(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "abbabbabbababaaaabbababab"; string Arg1 = "bababbaabbbababbbbababaab"; string Arg2 = "bbbbbbbbbbbbbbbbbbaaab"; verify_case(3, Arg2, find(Arg0, Arg1)); }

// END CUT HERE

};

// BEGIN CUT HERE
    int main() {
        TheLargestString ___test;
        ___test.run_test(-1);
    }
// END CUT HERE
