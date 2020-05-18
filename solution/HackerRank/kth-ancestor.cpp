#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector< pair<int, int> > vii;

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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

const int MAX_N = 100005;
const int LOG_N = 20;

int n;
vi e[MAX_N];
int h[MAX_N];
int p[MAX_N][LOG_N];


void add_node(int u) {
    foru(i,1,LOG_N-1)
        if (h[u] < (1<<i)) break;
        else p[u][i] = p[p[u][i-1]][i-1];
}

void dfs(int u) {
    add_node(u);
    int sz = size(e[u]);
    rep(i,sz) {
        int v = e[u][i];
        h[v] = h[u]+1;
        p[v][0] = u;
        dfs(v);
    }
}

void enter() {
    read(n);
    rep(i,MAX_N) {
        e[i].clear();
        h[i] = -1;
    }
    rep(i,n) {
        int u = read(), r = read();
        e[r].pb(u);
    }
    h[0] = 0;
    dfs(0);
}

int get_kth_ancestor(int u, int k) {
    if ((u < 1) or (h[u] < 1) or (k >= h[u])) return 0;
    ford(i,LOG_N-1,0)
        if (k >= (1<<i)) {
            u = p[u][i];
            k -= 1<<i;
        }
    return u;
}

void solve() {
    int nQ = read();
    rep(q_id, nQ) {
        int t = read();
        if (t == 0) {
            int u = read(), v = read();
            if (h[u] > -1) {
                h[v] = h[u]+1;
                p[v][0] = u;
                add_node(v);
            }
        }
        else if (t == 1) {
            int u = read();
            h[u] = - 1;
        }
        else {
            int u = read(), k = read();
            printf("%d\n",get_kth_ancestor(u, k));
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("kth-ancestor.in", "r", stdin);
    freopen("kth-ancestor.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id, nTest) {
        enter();
        solve();
    }
    return 0;
}
