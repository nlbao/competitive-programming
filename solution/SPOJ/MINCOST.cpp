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


const int MAXN = 102;
const int MAXC = int(2e9) + 9;

#define fillchar(a, x) memset((a), (x), sizeof(a))

struct Edge{
    int v, c, w, f, inv;
    Edge(){}
    Edge(int vv, int cc, int ww, int ff, int ii){
        this->v = vv;
        this->c = cc;
        this->w = ww;
        this->f = ff;
        this->inv = ii;
    }
};

int tmpz[MAXN][MAXN], tmpw[MAXN][MAXN], check[MAXN][MAXN];

int n, m, k, s, t;
int parent[MAXN], p_edge[MAXN], d[MAXN], state[MAXN];
deque <int> q;
vector <Edge> e[MAXN];

void addEdge(int i, int j, int c, int w, int f){
    int u = e[i].size(), v = e[j].size();
    e[i].push_back(Edge(j, c, w, 0, v));
    e[j].push_back(Edge(i, 0, -w, 0, u));
}

int findPath(){
    for (int i = 1; i <= n; ++i){
        d[i] = MAXC;
        state[i] = 0;
        parent[i] = p_edge[i] = -1;
    }
    d[s] = 0;
    q.push_back(s);
    while (!q.empty()) {
        int u = q.front();  q.pop_front();
        state[u] = 2;
        for (int i = 0, len = e[u].size(); i < len; ++i){
            if (e[u][i].f < e[u][i].c){
                int v = e[u][i].v;
                int tmp = d[u] + e[u][i].w;
                if (tmp < d[v]){
                    d[v] = tmp;
                    parent[v] = u;
                    p_edge[v] = i;
                    if (state[v] == 0) q.push_back(v);
                    else
                        if (state[v] == 2)
                            q.push_front(v);
                    state[v] = 1;
                }
            }
        }
    }
    return (parent[t] > -1);
}

int main() {
#ifdef DEBUG
	freopen("MINCOST.in", "r", stdin);
	freopen("MINCOST.out", "w", stdout);
#endif
    fillchar(check, 0);
    for (int i = 1; i <= n; ++i)
        e[i].clear();

    scanf("%d %d %d %d %d", &n, &m, &k, &s, &t);
    for (int i = 1; i <= m; ++i){
        int x, y, z, w;
        scanf("%d %d %d %d", &x, &y, &w, &z);
        tmpz[x][y] = tmpz[y][x] = z;
        tmpw[x][y] = tmpw[y][x] = w;
        check[x][y]= check[y][x] = 1;
    }

    for (int x = 1; x <= n; ++x)
        for (int y = 1; y <= n; ++y)
            if (check[x][y] == 1){
                addEdge(x, y, tmpz[x][y], tmpw[x][y], 0);
                // addEdge(y, x, tmpz[x][y], tmpw[x][y], 0);
            }

    ll flow = 0, cost = 0;
    while (findPath()){
        int addFlow = k - flow;
        if (addFlow == 0)
            break;
        for (int v = t; v != s; v = parent[v]){
            int u = parent[v], i = p_edge[v];
            addFlow = min(addFlow, e[u][i].c - e[u][i].f);
        }

        for (int v = t; v != s; v = parent[v]){
            int u = parent[v], i = p_edge[v], j = e[u][i].inv;
            e[u][i].f += addFlow;
            e[v][j].f -= addFlow;
            cost += ll(addFlow) * ll(e[u][i].w);
        }
        flow += addFlow;
    }

    if (flow < k)
        cout << "-1";
    else{
        cout << cost << endl;
        for (int i = 1; i <= n; ++i)
            for (int j = 0, len = e[i].size(); j < len; ++j)
                if (e[i][j].f > 0)
                    cout << i << " " << e[i][j].v << " " << e[i][j].f << endl;
        cout << "0 0 0";
    }
    return 0;
}