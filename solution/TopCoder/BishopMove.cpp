#include <cstdio>
#include <cmath>
#include <cstring>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vecint;
typedef pair<int, int> ppi;
typedef vector< pair<int, int> > vecppi;

#define fill(a,x) memset(a, (x), sizeof(a))
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }

const int MAX_N = 8;
const int oo = 100000;
queue<pair<int, int> > q;

int d[MAX_N][MAX_N];


void add(int u, int v, int value) {
	
	if (u < 0 || u >= MAX_N || v < 0 || v >= MAX_N)
		return;
	if (d[u][v] <= value+1) return;
	d[u][v] = value+1;
	q.push(make_pair(u, v));
}


class BishopMove {
public:
	int howManyMoves(int r1, int c1, int r2, int c2) {
		for (int i = 0; i < MAX_N; ++i)
			for (int j = 0; j < MAX_N; ++j)
				d[i][j] = oo;
		d[r1][c1] = 0;
		q.push(make_pair(r1, c1));
		while (!q.empty()) {
			int u = q.front().first, v = q.front().second;
			q.pop();
			for (int k = 1; k < MAX_N; ++k) {
				add(u+k, v+k, d[u][v]);
				add(u+k, v-k, d[u][v]);
				add(u-k, v+k, d[u][v]);
				add(u-k, v-k, d[u][v]);
			}
		}
		if (d[r2][c2] >= oo) return -1;
		return d[r2][c2];
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 7; int Arg3 = 3; int Arg4 = 1; verify_case(0, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_1() { int Arg0 = 2; int Arg1 = 5; int Arg2 = 2; int Arg3 = 5; int Arg4 = 0; verify_case(1, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_2() { int Arg0 = 1; int Arg1 = 3; int Arg2 = 5; int Arg3 = 5; int Arg4 = 2; verify_case(2, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 6; int Arg2 = 7; int Arg3 = 4; int Arg4 = -1; verify_case(3, Arg4, howManyMoves(Arg0, Arg1, Arg2, Arg3)); }

// END CUT HERE

};
 
// BEGIN CUT HERE 
    int main() {
        BishopMove ___test; 
        ___test.run_test(-1); 
       int X ;
       scanf("%d",&X) ;
    } 
// END CUT HERE
