// Fast flow - Dinic algorithm
// Bounded Flow: low <= f <= height
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