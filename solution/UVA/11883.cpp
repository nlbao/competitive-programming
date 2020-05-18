#include <cstdio>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <functional>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define filla(a, x) memset((a), (x), sizeof(a))
#define foreach(it, x) for (typeof((x).begin()) (it) = (x).begin(); (it) != (x).end(); ++(it))
//#define for_each(it, x) for (auto (it) = (x).begin(); (it) != (x).end(); ++(it))

int read()  {   int x;  scanf("%d", &x);    return x;   }
int readln()  {   int x;  scanf("%d\n", &x);    return x;   }

const int MAX_N = 555;
const double oo = 1e9;
const double EPSILON = 1e-7;


struct Edge {
    int vertex;
    double v, a;
    bool repair;

    Edge(int u = -1, double _v = 0, double _a = 0) {
        vertex = u;
        v = _v;
        a = _a;
        repair = false;
    }
};


int n, m;
vector<Edge> e[MAX_N];
double d[MAX_N];
set<pair<double, int> > q;


double dijkstra(int s, int t, double d[]) {
    for (int i = 1; i <= n; ++i)
        d[i] = oo;
    d[s] = 0;
    q.clear();
    q.insert(make_pair(0, s));

    while (!q.empty()) {
        int u = q.begin()->second;
        double l = q.begin()->first;
        q.erase(q.begin());

        if (l + EPSILON < d[u]) continue;

        for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
            if (e[u][i].repair) continue;
            int v = e[u][i].vertex;
            double cost = l + e[u][i].v;
            if (cost < d[v] + EPSILON) {
                q.erase(make_pair(d[v], v));
                d[v] = cost;
                q.insert(make_pair(cost, v));
            }
        }
    }
    return d[t];
}


int main() {
//    freopen("D.in", "r", stdin);
//    freopen("D.out", "w", stdout);

    while (true) {
        scanf("%d%d", &n, &m);
        if (n == 0) break;
        for (int i = 0; i <= n; ++i) e[i].clear();
        for (int i = 0; i < m; ++i) {
            int x, y;
            double v, a;
            scanf("%d%d%lf%lf", &x, &y, &v, &a);
            e[x].push_back(Edge(y, v, a));
            e[y].push_back(Edge(x, v, a));
        }

        double ans = dijkstra(1, n, d);

        for (int u = 1; u <= n; ++u)
            for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
                int v = e[u][i].vertex;
                e[u][i].repair = true;
                double f_u = dijkstra(1, u, d);
                double g_v = dijkstra(v, n, d);
                e[u][i].repair = false;

                double t = 0;
                if (fabs(e[u][i].a - 1.0) > EPSILON) {
                    t = log(e[u][i].v * log(e[u][i].a)) / log(e[u][i].a) - f_u;
                    if (t < 0) t = 0;
                }

                double cost = e[u][i].v / pow(e[u][i].a, f_u + t);
                ans = min(ans, f_u + t + cost + g_v);
                // printf("%d %d: %.4lf, %.4lf, %.4lf\n", u, v, f_u, g_v, f_u + cost + g_v);
            }
        printf("%.3lf\n", ans);
    }
    return 0;
}
