#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <math.h>
#include <cstring>
#include <string.h>
#include <stdlib.h>
#include <algorithm>

#define rep(i, n) for (int i=0;i<n;i++)
#define repr(i, n) for (int i = n - 1;i>=0;i--)
#define fr(i, a, b) for (int i=a;i<=b;i++)
#define frr(i, a, b) for (int i=b;i>=a;i--)
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define int64 long long
#define INF 111222333
#define N 60

using namespace std;

inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
inline int gcd(int a, int b) { if (a % b) return gcd(b, a % b); else return b; }
inline int lcm(int a, int b) { return (a * (b / gcd(a, b) )); }

inline int And(int mask, int bit) { return mask & (1 << bit); }
inline int Or(int mask, int bit) { return mask | (1 << bit); }
inline int Xor(int mask, int bit) { return mask ^ (1 << bit); }

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
int r[N], c[N], adj[N][N];
int a[N][N], ans[N][N], deg[N], p[N];
void dinic(int n, int s, int t) {
    int u, v, z, f, mf;
    mf = 0;
    for (int i = 0;i < n;i++) deg[i] = 0;
    for (u = 0;u < n;u++) for (v = 0;v < n;v++) if (a[u][v] || a[v][u])
        adj[u][deg[u]++] = v;
    while ( true ) {
        for (int i = 0;i < n;i++) p[i] = -1;
        p[s] = -2;
        queue <int> q; q.push(s);
        while ( !q.empty() && p[t] == -1) {
            int u = q.front(); q.pop();
            for (int i = 0;i < deg[u];i++) {
                int v = adj[u][i];
                if (p[v] == -1 && a[u][v])
                    p[v] = u, q.push(v);
            }
        }
        if (p[t] == -1) break;
        for (z = 0;z < n;z++) if (p[z] != -1 && a[z][t]) {
            f = a[z][t];
            for (v = z, u = p[v]; u>=0; v = u, u = p[v]) f = min(f, a[u][v]);
            a[z][t]-=f;
            a[t][z]+=f;
            for (v = z, u = p[v]; u>=0; v = u, u = p[v]) {
                a[u][v]-=f;
                a[v][u]+=f;
            }
            mf+=f;
        }
    }
}
int main(){
    #ifndef ONLINE_JUDGE
    freopen("vmmtfive.in", "r", stdin);
    freopen("vmmtfive.out", "w", stdout);
    #endif
    int s, t;
    for (int i = 0;i < 5;i++) scanf("%d", &r[i]);
    for (int i = 0;i < 5;i++) scanf("%d", &c[i]);
    s = 10; t = 11;
    for (int i = 0;i <= t;i++)
        for (int j = 0;j <= t;j++)
            a[i][j] = 0;

    for (int i = 0;i < 5;i++)
        for (int j = 0;j < 5;j++)
            a[i][j + 5] = 24;

    for (int i = 0;i < 5;i++)
        a[s][i] = r[i] - 5;
    for (int i = 0;i < 5;i++)
        a[i + 5][t] = c[i] - 5;

    dinic(t + 1, s, t);
    for (int i = 0;i < 5;i++)
        for (int j = 0;j < 5;j++)
            ans[i][j] = 25 - a[i][j + 5];
    for (int i = 0;i < 5;i++) {
        for (int j = 0;j < 5;j++) {
            if (j) printf(" ");
            printf("%d", ans[i][j]);
        }
        puts("");
    }
}


