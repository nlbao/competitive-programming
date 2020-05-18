#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PI;

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

const int MAX_N = 604;

int n, m;
VI a, x, y;

void parse(vector <string> vs, VI &a) {
   a.clear();
   string s = "";
   int m = size(vs), x = 0;
   rep(i,m) s += vs[i];
   m = size(s);
   for(int i = 0; i < m; ++i)
      if (s[i] == ' ') {
         a.pb(x);
         x = 0;
      }
      else x = x*10 + s[i]-'0';
   a.pb(x);
}

void get_line(double x1, double y1, double x2, double y2,  double &a, double &b, double &c) {
   if (x1 == x2) {   a = 1;   b = 0;   c = -x1; }
   else {   a = (y1-y2)/(x1-x2);    b = -1;  c = (x1*y2-x2*y1)/(x1-x2); }
}

ll find_left(double x) {
   int i = 0;
   while (i < n && a[i] < x) ++i;
   return i;
}

ll find_right(double x) {
   int i = n-1;
   while (i >= 0 && a[i] > x) --i;
   return n-1-i;
}

class Ear {
   public:
   long long getCount(vector <string> redX, vector <string> blueX, vector <string> blueY) {
      parse(redX,a);
      parse(blueX,x);
      parse(blueY,y);
      n = size(a);   m = size(x);
      sort(all(a));

      rep(i,n) cout << a[i] << " ";
      cout << endl;

      ll res = 0;
      rep(i,m)
         rep(j,m) {
            if (y[j] >= y[i]) continue;
            double aa, bb, cc;
            get_line(x[i],y[i],x[j],y[j],aa,bb,cc);
            double t = -cc/aa;
            /*ll l1 = find_left(min(double(x[j]),t)), l2 = find_left(min(double(x[i]),t));
            ll r1 = find_right(max(double(x[j]),t)), r2 = find_right(max(double(x[i]),t));
            */
            ll l1 = 0, l2 = 0, r1 = 0, r2 = 0;
            bool check = false;
            rep(k,n)
               if (a[k] != t) {
                  if (a[k] < min(x[i],x[j])) ++l1;
                  else if (x[i] <= a[k] && a[k] < x[j]) ++l2;
                  else if (max(x[i],x[j]) < a[k]) ++r1;
                  else if (x[j] < a[k] && a[k] <= x[i]) ++r2;
               }
               else check = true;

            cout << x[i] << " " << y[i] << "    " << x[j] << " " << y[j];
            cout << "           "  << aa << "    " << l1 << " " << l2 << "     "  << r1 << " " << r2 << "       ";
            cout << (l1*l2 + l1*(l1-1)/2) * (r1*r2 + r1*(r1-1)/2) << endl;

            res += (l1*l2 + l1*(l1-1)/2) * (r1*r2 + r1*(r1-1)/2);
            if (check)
               if (t < x[j]) {
                  l1 = 0;
                  rep(k,n) if (a[k] < t) ++l1;
                  res += l1*(r1*r2 + r1*(r1-1)/2);
                  cout << "!!!! " << l1 << "       " << l1*(r1*r2 + r1*(r1-1)/2) << endl;
               }
               else if (t > x[j]) {

               }
         }
      return res;
   }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"3 2 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"5 4"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 1LL; verify_case(0, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_1() { string Arr0[] = {"3 2 8 7"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"2 8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"3 4"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(1, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_2() { string Arr0[] = {"1 2 6 9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"3 6 8 5"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1 5 4 3"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 4LL; verify_case(2, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_3() { string Arr0[] = {"10000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"10000 9999"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"10000 9999"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 0LL; verify_case(3, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_4() { string Arr0[] = {"100 2", "00", " 39", "9", " 800 900 9", "99"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"15", "0 250 ", "349"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"2 3 1"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 12LL; verify_case(4, Arg3, getCount(Arg0, Arg1, Arg2)); }
	void test_case_5() { string Arr0[] = {"1", " ", "2", " ", "3", " ", "4 5 6", " 7 8 9"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arr1[] = {"4", " ", "5", " ", "6", " 7 ", "8"}; vector <string> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); string Arr2[] = {"1", " 2 ", "3 4", " 5"}; vector <string> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); long long Arg3 = 204LL; verify_case(5, Arg3, getCount(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

 // BEGIN CUT HERE
    int main()
        {
        Ear ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
