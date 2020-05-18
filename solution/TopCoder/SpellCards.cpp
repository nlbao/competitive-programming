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

const int MAX_N = 55;
const ll BASE = 10007;

struct node {
   int id[MAX_N];
   ll value;
   node (int b[], int n, ll v) {
      foru(i,1,n) id[i] = b[i];
      value = v;
   }
};

int n;
int level[MAX_N], dam[MAX_N], id[MAX_N];
map<ll,ll> f[MAX_N];
vector<node> q[MAX_N];

void push(int len, node x) {
   if (len == 0) f[0][0] = max(f[0][0], x.value);
   foru(i,1,len) {
      ll h = 0;
      foru(j,i,len) h = h*BASE + ll(x.id[j]);
      foru(j,1,i-1) h = h*BASE + ll(x.id[j]);
      if (f[len].count(h) == 0) {
         f[len][h] = x.value;
         foru(j,i,len) id[j-i+1] = x.id[j];
         foru(j,1,i-1) id[len-i+1+j] = x.id[j];
         q[len].pb(node(id,len,x.value));
      }
      else f[len][h] = max(f[len][h],x.value);
   }
}

class SpellCards {
   public:
   int maxDamage(vector <int> l, vector <int> d) {
      n = size(l);
      foru(i,1,n) {
         level[i] = l[i-1];
         dam[i] = d[i-1];
      }
      rep(i,MAX_N) f[i].clear();
      f[0][0] = 0;

      foru(i,1,n) id[i] = i;
      push(n,node(id,n,0));

      ford(len,n,1) {
         int sz = size(q[len]);
         rep(k,sz) {
            node x = q[len][k];
            //foru(i,1,len) cout << x.id[i] << " ";
            //cout << "        " << x.value << endl;
            int t = level[x.id[1]];
            if (t > len) continue;
            foru(i,t+1,len) id[i-t] = x.id[i];
            push(len-t,node(id,len-t,x.value + dam[x.id[1]]));
         }
      }
      //system("pause");
      return f[0][0];
   }


// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 60; verify_case(0, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 30; verify_case(1, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {4,4,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 0; verify_case(2, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {50,1,50,1,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,20,30,40,50}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 60; verify_case(3, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_4() { int Arr0[] = {2,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {40,40,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 80; verify_case(4, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_5() { int Arr0[] = {1,2,1,1,3,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {10,40,10,10,90,40,10}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 170; verify_case(5, Arg2, maxDamage(Arg0, Arg1)); }
	void test_case_6() { int Arr0[] = {1,2,2,3,1,4,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {113,253,523,941,250,534,454}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 1918; verify_case(6, Arg2, maxDamage(Arg0, Arg1)); }

// END CUT HERE

};

 // BEGIN CUT HERE
    int main()
        {
        SpellCards ___test;
        ___test.run_test(-1);
        }
    // END CUT HERE
