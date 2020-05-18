#include <bits/stdc++.h>

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

const int MAX_N = 2e5 + 5;


int n, m, s;
int d[MAX_N];
bool visited[MAX_N];
queue<int> q;
set<int> a[2];
vector<int> e[MAX_N];


void solve() {
    filla(visited, false);
    a[0].clear();   a[1].clear();
    
    d[s] = 0;
    q.push(s);
    visited[s] = true;
    int t = 0;
    for (int i = 1; i <= n; ++i)
        if (i != s)
            a[t].insert(i);

    while (!q.empty()) {
        int tt = t^1;
        int u = q.front();  q.pop();
        foreach(it, e[u]) {
            int v = *it;
            if (!visited[v]) {
                a[t].erase(v);
                a[tt].insert(v);
            }
        }
        foreach(it, a[t]) {
            int v = *it;
            d[v] = d[u]+1;
            q.push(v);
            visited[v] = true;
        }
        visited[u] = true;
        a[t].clear();
        t = tt;
    }

    for (int i = 1; i <= n; ++i)
        if (i != s)
            printf("%d ", d[i]);
    printf("\n");
}


int main() {
#ifdef DEBUG
	freopen("rust-murderer-02.in", "r", stdin);
	freopen("rust-murderer.out", "w", stdout);
#endif
	int nTest = read();
	while (nTest--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; ++i) e[i].clear();
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            e[x].push_back(y);
            e[y].push_back(x);
        }
        s = read();
        solve();
	}
	return 0;
}
