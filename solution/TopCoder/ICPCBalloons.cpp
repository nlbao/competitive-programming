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

const int MAX_N = 107;
const int MAX_M = 17;
const int oo = 10000000;

int n, m, a[MAX_N];
VI b[2], t[2];

int check(int id) {
   int n = size(t[id]), m = size(b[id]), res = 0;
   bool ok_n[MAX_N], ok_m[MAX_N];
   int d[MAX_N];
   fill(ok_n,false);
   fill(ok_m,false);
   rep(i,m) d[i] = b[id][i];

   ford(i,m-1,0)
      ford(j,n-1,0)
         if (t[id][j] > 0 && d[i] >= t[id][j]) {
            if (ok_m[i] || ok_n[j]) res += t[id][j];
            ok_m[i] = ok_n[j] = true;
            d[i] -= t[id][j];
            t[id][j] = 0;
         }

   ford(i,m-1,0)
      ford(j,n-1,0) {
         if (d[i] < 1) break;
         if (t[id][j] < 1) continue;
         int x = min(d[i],t[id][j]);
         if (ok_m[i] || ok_n[j]) res += x;
         ok_m[i] = ok_n[j] = true;
         d[i] -= x;
         t[id][j] -= x;
      }

   rep(i,n)
      if (t[id][i]) return oo;
   return res;
}

int cal(int mask) {
   rep(i,2) t[i].clear();
   rep(i,m) t[(mask>>i)&1].pb(a[i]);

   if (mask == 56) {
      rep(i,size(t[0])) cout << t[0][i]<< " "; cout << endl;
      cout << "!!! " << check(0) << " " << check(1) << endl;
      return oo;
   }

   return check(0)+check(1);
}

class ICPCBalloons {
    public:
    int minRepaintings(vector <int> balloonCount, string balloonSize, vector <int> maxAccepted) {
      n = size(balloonCount);
      m = size(maxAccepted);
      sort(all(balloonCount));
      rep(i,2) b[i].clear();
      rep(i,n) b[(balloonSize[i] == 'M')].pb(balloonCount[i]);
      rep(i,m) a[i] = maxAccepted[i];
      sort(a,a+m);
      rep(i,m) cout << a[i] << " " ; cout << endl;

      int res = oo;
      rep(i,1<<m) res = min(res,cal(i));
      if (res == oo) res = -1;
      return res;
    }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "L"; int Arr2[] = {1,2,3,4,5}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 10; verify_case(0, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "M"; int Arr2[] = {10,20,30,40,50}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(1, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {5,6,1,5,6,1,5,6,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MLMMLMMLM"; int Arr2[] = {7,7,4,4,7,7}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 6; verify_case(2, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {100,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ML"; int Arr2[] = {50,51,51}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = -1; verify_case(3, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {8,5,1,4,1,1,3,1,3,3,5,4,5,6,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "MMMLLLMMLLMLMLM"; int Arr2[] = {3,5,3,3,5,6,4,6,4,2,3,7,1,5,2}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 5; verify_case(4, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {1,18,4,7,19,7,7,1,4,8,10,5,14,13,8,22,6,3,13,5,3,4,2,1,3,15,19,4,5,9,4,11,2,7,12,20,11,26,22,7,2,10,9,20,13,20,2,9,11,9}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "LLMLLLLMLLLLLLLLLLLLMLLLLLLLLLLMMLMLLLMLLLLLLLLMLL"; int Arr2[] = {44,59,29,53,16,23,13,14,29,42,13,15,66,4,47}; vector <int> Arg2(Arr2, Arr2 + (sizeof(Arr2) / sizeof(Arr2[0]))); int Arg3 = 210; verify_case(5, Arg3, minRepaintings(Arg0, Arg1, Arg2)); }

// END CUT HERE

};

 // BEGIN CUT HERE
    int main()
        {
        ICPCBalloons ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
