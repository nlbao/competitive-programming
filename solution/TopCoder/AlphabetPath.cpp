#include <sstream>
#include <iostream>
#include <vector>
#include <string.h>

using namespace std ;

class AlphabetPath {
    public:
    string doesItExist(vector <string> letterMaze) {
        int dx[4] = {0,0,-1,+1};
        int dy[4] = {-1,+1,0,0};
        int n = letterMaze.size();
        int m = letterMaze[0].length();
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (letterMaze[i][j] == 'A') {
                    x = i;  y = j;
                }
        if (letterMaze[x][y] != 'A') return "NO";
        char ch;
        for (ch = 'B'; ch < 'Z'; ++ch) {
            int check = 0;
            for (int k = 0; k < 4; ++k) {
                int x0 = x+dx[k], y0 = y+dy[k];
                if (!((x0 < 0) || (x0 >= n) || (y0 < 0) || (y0 >= m)))
                    if (letterMaze[x0][y0] == ch) {
                        check = 1;
                        x = x0; y = y0;
                        break;
                    }
            }
            if (check == 0) return "NO";
        }
        if (ch == 'Z') return "YES";
        else return "NO";
  }

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(0, Arg1, doesItExist(Arg0)); }
	void test_case_1() { string Arr0[] = {"ADEHI..Z",
 "BCFGJK.Y",
 ".PONML.X",
 ".QRSTUVW"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(1, Arg1, doesItExist(Arg0)); }
	void test_case_2() { string Arr0[] = {"ACBDEFGHIJKLMNOPQRSTUVWXYZ"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(2, Arg1, doesItExist(Arg0)); }
	void test_case_3() { string Arr0[] = {"ABC.......",
 "...DEFGHIJ",
 "TSRQPONMLK",
 "UVWXYZ...."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NO"; verify_case(3, Arg1, doesItExist(Arg0)); }
	void test_case_4() { string Arr0[] = {"..............",
 "..............",
 "..............",
 "...DEFGHIJK...",
 "...C......L...",
 "...B......M...",
 "...A......N...",
 "..........O...",
 "..ZY..TSRQP...",
 "...XWVU.......",
 ".............."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "YES"; verify_case(4, Arg1, doesItExist(Arg0)); }

// END CUT HERE

};

 // BEGIN CUT HERE
    int main()
        {
        AlphabetPath ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
