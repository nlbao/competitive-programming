#include <cstdio>
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
typedef pair<int, int> pii;

#define filla(a,x) memset(a, (x), sizeof(a))
#define for_each(it, X) for(typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 5*int(1e4)+5;


// int nX, nY, m;
// vector<int> e[MAX_N];
// int d[MAX_N], matchX[MAX_N], matchY[MAX_N], q[MAX_N];

// bool bfs_matching() {
//     int l = 0, r = -1;
//     for (int i = 1; i <= nX; ++i)
//         if (matchX[i]) d[i] = 0;
//         else {
//             d[i] = 1;
//             q[++r] = i;
//         }
//     d[0] = 0;

//     while (l <= r) {
//         int u = q[l++];
//         for_each(it, e[u]) {
//             int v = matchY[*it];
//             if (!d[v]) {
//                 d[v] = d[u]+1;
//                 if (!v) return true;
//                 q[++r] = v;
//             }
//         }
//     }
//     return false;
// }


// bool dfs_matching(int u) {
//     if (u == 0) return true;
//     for_each(it, e[u]) {
//         int v = matchY[*it];
//         if (d[v] == d[u]+1 && dfs_matching(v)) {
//             matchX[u] = *it;
//             matchY[*it] = u;
//             return true;
//         }
//     }
//     d[u] = 0;
//     return false;
// }

#define foreach(it, x) for(__typeof(x.begin()) it = x.begin(); it != x.end(); it++)

struct Matching {
    static const int oo = 1000111;
    int n;
    vector<int> matchL, matchR, dist;
    vector<bool> seen;
    vector< vector<int> > ke;

    Matching(int n) : n(n), matchL(n+1), matchR(n+1), dist(n+1), seen(n+1, false), ke(n+1) {}

    void addEdge(int u, int v) {
        ke[u].push_back(v);
    }

    bool bfs() {
        queue<int> qu;
        for(int u = 1; u <= n; ++u)
            if (!matchL[u]) {
                dist[u] = 0;
                qu.push(u);
            } else dist[u] = oo;
        dist[0] = oo;
        while (!qu.empty()) {
            int u = qu.front(); qu.pop();
            foreach(it, ke[u]) {
                int v = *it;
                if (dist[matchR[v]] == oo) {
                    dist[matchR[v]] = dist[u] + 1;
                    qu.push(matchR[v]);
                }
            }
        }
        return dist[0] != oo;
    }

    bool dfs(int u) {
        if (u) {
            foreach(it, ke[u]) {
                int v = *it;
                if (dist[matchR[v]] == dist[u] + 1 && dfs(matchR[v])) {
                    matchL[u] = v;
                    matchR[v] = u;
                    return true;
                }
            }
            dist[u] = oo;
            return false;
        }
        return true;
    }

    int match() {
        int res = 0;
        while (bfs()) {
            for(int u = 1; u <= n; ++u)
                if (!matchL[u])
                    if (dfs(u)) ++res;
        }
        return res;
    }
};


int main() {
#ifdef DEBUG
    freopen("MATCHING.in", "r", stdin);
    freopen("MATCHING.out", "w", stdout);
#endif
    int nX, nY, m;
    scanf("%d%d%d", &nX, &nY, &m);
    Matching matching(max(nX, nY));
    for (int i = 0; i < m; ++i) {
        int x, y;
        scanf("%d%d", &x, &y);
        matching.addEdge(x, y);
    }

    printf("%d\n", matching.match());
    return 0;
}