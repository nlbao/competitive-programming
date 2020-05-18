#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
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
#define sz(a) int(a.size())
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
const int L = 32;

struct node {
    int link[2];
    node () {
        link[0] = link[1] = -1;
    }
};


int n, nNode;
int a[MAX_N];
vii e[MAX_N];
bool ok[MAX_N];
node trie[MAX_N*L];

void dfs(int u, int f) {
    ok[u] = false;
    a[u] = f;
    int szE = sz(e[u]);
    rep(i, szE) {
        int v = e[u][i].sc;
        if (ok[v])
            dfs(v, f^e[u][i].fr);
    }
}


int get(int value) {
    int res = 0, p = 0;
    ford(i, L-1, 0) {
        if (p == -1) return res;
        int x = (value>>i)&1;
        if (trie[p].link[1-x] != -1) {
            res += (1<<i);
            p = trie[p].link[1-x];
        }
        else p = trie[p].link[x];
    }
    return res;
}


void add(int value) {
    int p = 0;
    ford(i, L-1, 0) {
        int x = (value>>i)&1;
        if (trie[p].link[x] == -1) {
            trie[nNode] = node();
            trie[p].link[x] = nNode++;
        }
        p = trie[p].link[x];
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("PPTREE.in", "r", stdin);
    freopen("PPTREE.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id, nTest) {
        read(n);
        foru(i, 1, n) e[i].clear();
        rep(i, n-1) {
            int x, y, w;
            scanf("%d%d%d", &x, &y, &w);
            e[x].pb(mp(w, y));
            e[y].pb(mp(w, x));
        }

        fill(ok, true);
        dfs(1, 0);
        nNode = 1;
        trie[0] = node();

        int res = 0;
        foru(i, 1, n) {
            res = max(res, get(a[i]));
            add(a[i]);
        }
        printf("%d\n", res);
    }
    return 0;
}
