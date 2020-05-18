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


const int MAX_N = 60;


struct Flow {
    static const int oo = 1e9;

    struct Edge {
        int v, c, f, inv;
        Edge() {}
        Edge(int v, int c, int inv): v(v), c(c), f(0), inv(inv) {}
    };

    int n, s, t;
    vector<vector<Edge> > e;
    vector<int> d, pos, sz;
    queue<int> q;

    Flow(int n, int s = 1, int t = 2): n(n), s(s), t(t), e(n+1), d(n+1), pos(n+1), sz(n+1, 0) {}

    void addEdge(int u, int v, int c) {
        e[u].push_back(Edge(v, c, sz[v]++));
        e[v].push_back(Edge(u, 0, sz[u]++));
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

    int maxFlow() {
        int flow = 0;
        while (bfs()) {
            fillv(pos, 0);
            fill(pos.begin(), pos.end(), 0);
            for (int delta = 1; delta > 0; )
                flow += (delta = dfs(s, oo));
        }
        return flow;
    }

    int getAns(int u) {
    	foreach(it, e[u]) {
    		int v = it->v;
			if (v != s && v != t && it->c > 0 && it->f == it->c)
				return v;
    	}
    	return -1;
    }
};


int n;
int a[MAX_N], id[MAX_N][2];


bool solve() {
	int nC = 2, sum = 0;
	for (int i = 0; i < n; ++i) {
		id[i][0] = ++nC;
		id[i][1] = ++nC;
		sum += a[i];
	}
	if (sum != n) return false;
	Flow flow(nC);
	for (int i = 0; i < n; ++i) {
		flow.addEdge(1, id[i][0], 1);
		flow.addEdge(id[i][1], 2, a[i]);
		for (int j = 0; j < n; ++j)
			if (i != j)
				flow.addEdge(id[i][0], id[j][1], 1);
	}
	int maxFlow = flow.maxFlow();
	if (maxFlow == sum) {
		for (int i = 0; i < n; ++i) {
			int t = flow.getAns(id[i][0]), v = -1;
			for (int k = 0; k < n; ++k)
				if (id[k][1] == t) {
					v = k+1;
					break;
				}
			printf("%d", v);
			if (i < n-1) printf(" ");
		}
		printf("\n");
		return true;
	}
	return false;
}


int main() {
#ifdef DEBUG
	freopen("CHEFVOTE.in", "r", stdin);
	freopen("CHEFVOTE.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
		n = read();
		for (int i = 0; i < n; ++i)
			a[i] = read();
		if (!solve()) printf("-1\n");
	}
	return 0;
}