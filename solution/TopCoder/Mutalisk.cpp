#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <functional>
#include <bitset>

// #pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

#define filla(a, x) memset(a, x, sizeof(a))
#define fillv(v, x) memset(&v[0], x, v.size() * sizeof(v[0]))
#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)
#define sqr(x) ((x)*(x))

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }


const int oo = 1e9;


struct BoundedFlow {
    static const int oo = 1e9;

    struct Edge {
        int v, c, f, inv;
        Edge() {}
        Edge(int v, int c, int inv): v(v), c(c), f(0), inv(inv) {}
    };

    int n, s, t, sumLow;
    vector<vector<Edge> > e;
    vector<int> d, pos, sz;
    queue<int> q;

    BoundedFlow(int n, int ss = 1, int tt = 2): n(n), e(n+3), d(n+3), pos(n+3), sz(n+3, 0) {
        s = n+1;    // s in new graph
        t = n+2;    // t in new graph
        addEdgeNewGraph(tt, ss, oo);
        sumLow = 0;
    }

    void addEdgeNewGraph(int u, int v, int c) {
        e[u].push_back(Edge(v, c, sz[v]++));
        e[v].push_back(Edge(u, 0, sz[u]++));
    }

    void addEdge(int u, int v, int low, int height) {
        sumLow += low;
        addEdgeNewGraph(s, v, low);
        addEdgeNewGraph(u, t, low);
        if (height >= oo) addEdgeNewGraph(u, v, oo);
        else addEdgeNewGraph(u, v, height-low);
    }

    bool bfs() {
        fillv(d, 0);
        d[s] = 1;
        while (!q.empty()) q.pop();
        q.push(s);
        while (!q.empty()) {
            int u = q.front();  q.pop();
            if (u == t) return true;
            foreach(it, e[u]) {
                int v = it->v;
                if (!d[v] && it->f < it->c) {
                    d[v] = d[u]+1;
                    q.push(v);
                }
            }
        }
        return false;
    }

    int dfs(int u, int flow) {
        if (u == t || flow == 0) return flow;
        for (; pos[u] < sz[u]; ++pos[u]) {
            int i = pos[u], v = e[u][i].v;
            if (d[v] == d[u]+1) {
                int delta = dfs(v, min(flow, e[u][i].c - e[u][i].f));
                if (delta) {
                    e[u][i].f += delta;
                    e[v][e[u][i].inv].f -= delta;
                    return delta;
                }
            }
        }
        return 0;
    }

    bool hasSolution() {
        int flow = 0;
        while (bfs()) {
            fillv(pos, 0);
            fill(pos.begin(), pos.end(), 0);
            for (int delta = 1; delta > 0; )
                flow += (delta = dfs(s, oo));
        }
        return flow == sumLow;
    }
};


const int MAX_N = 24;


int n, sumValue;
int value[MAX_N];


bool check(int k) {
	int m = 2+3+n;
	BoundedFlow flow(m);
	flow.addEdge(1, 3, 0, k * 9);
	flow.addEdge(1, 4, 0, k * 3);
	flow.addEdge(1, 5, 0, k * 1);
	for (int i = 0; i < n; ++i) {
		int u = 5+i+1;
		for (int t = 0; t < k; ++t) {
            // flow.addEdge(3, u, 0, 9);
            // flow.addEdge(4, u, 0, 3);
            // flow.addEdge(5, u, 0, 1);
			flow.addEdge(3, u, 9, 9);
			flow.addEdge(4, u, 3, 3);
			flow.addEdge(5, u, 1, 1);
		}
		flow.addEdge(u, 2, value[i], oo);
	}
	// int maxFlow = flow.maxFlow();
    bool ok = flow.hasSolution();
    // cout << "    " << k << " " << maxFlow << " " << sumValue << endl;
	cout << "	" << k << " " << ok << " " << sumValue << endl;
    return ok;
	// return maxFlow >= sumValue;
}


class Mutalisk {
public:
	int minimalAttacks(vector <int> a) {
		n = a.size();
        if (n == 1) return a[0] / 9 + int((a[0]%9) > 0);
        if (n == 2) {
            int ans = 0;
            while (a[0] > 0 && a[1] > 0) {
                ++ans;
                if (a[0] < a[1]) swap(a[0], a[1]);
                a[0] -= 9;
                a[1] -= 3;
            }
            return ans;
        }

		sumValue = 0;
		for (int i = 0; i < n; ++i) {
			value[i] = a[i];
			sumValue += a[i];
			// cout << i << " " << value[i] << endl;
		}
		// int value[3] = {9, 3, 1};
		int ans = -1;
		int l = 1, r = 60 * n;
		while (l <= r) {
			int mid = (l+r)>>1;
			if (check(mid)) {
				ans = mid;
				r = mid-1;
			}
			else l = mid+1;
			// cout << "	" << l << " " << r << endl;
		}
		return ans;
	}

// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {12,10,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, minimalAttacks(Arg0)); }
	void test_case_1() { int Arr0[] = {54,18,6}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(1, Arg1, minimalAttacks(Arg0)); }
	void test_case_2() { int Arr0[] = {1,1,1,1,1,1,1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(2, Arg1, minimalAttacks(Arg0)); }
	void test_case_3() { int Arr0[] = {55,60,53}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; verify_case(3, Arg1, minimalAttacks(Arg0)); }
	void test_case_4() { int Arr0[] = {60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, minimalAttacks(Arg0)); }
	void test_case_5() { int Arr0[] = {60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60,60}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 93; verify_case(5, Arg1, minimalAttacks(Arg0)); }

// END CUT HERE

};

// BEGIN CUT HERE
int main() {
	Mutalisk ___test;
	// ___test.run_test(-1);
	___test.run_test(2);
	cin.get();
}
// END CUT HERE
