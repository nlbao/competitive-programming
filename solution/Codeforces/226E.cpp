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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

int read() {   int x;   scanf("%d",&x);   return x;   }
int readln() {   int x;   scanf("%d\n",&x);   return x;   }

const int MAX_N = 2*int(1e5)+5;
const int MAX_LOG = 19;

struct Node {
    int sum;
    Node *pLeft, *pRight;
    Node(int sum, Node* pLeft, Node* pRight): sum(sum), pLeft(pLeft), pRight(pRight) {};
};

int n, m, logN, pos, posLeft, posRight, value;
int a[MAX_N], h[MAX_N], start[MAX_N], finish[MAX_N];
int p[MAX_LOG][MAX_N];
vector<int> e[MAX_N];
Node* root[MAX_N];
bool ok[MAX_N];


void dfs(int u) {
    ok[u] = false;
    for (int i = 1; i <= logN; ++i)
        if (h[u] - (1<<i) > 0) p[i][u] = p[i-1][p[i-1][u]];
        else p[i][u] = -1;
    start[u] = ++m;
    for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
        int v = e[u][i];
        if (ok[v]) {
            p[0][v] = u;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
    finish[u] = ++m;
}


int lca(int u, int v) {
    if (h[u] < h[v]) return lca(v, u);
    if (h[u] > h[v])
        for (int i = logN; i >= 0; --i)
            if (h[u] - (1<<i) >= h[v])
                u = p[i][u];
    if (u == v) return u;
    for (int i = logN; i >= 0; --i)
        if (p[i][u] != p[i][v]) {
            u = p[i][u];
            v = p[i][v];
        }
    return p[0][u];
}


inline int getSum(Node* p) {   return p ? p->sum : 0;  }
inline Node* getLeft(Node* p) {    return p ? p->pLeft : NULL;  }
inline Node* getRight(Node* p) {    return p ? p->pRight : NULL;    }


Node* build_tree(int l, int r) {
    if (l > r) return NULL;
    if (l == r) return new Node(0, NULL, NULL);
    int mid = (l+r)>>1;
    return new Node(0, build_tree(l, mid), build_tree(mid+1, r));
}


Node* update(Node* p, int l, int r) {
    if (l > r) return NULL;
    if (l > pos || r < pos) return p;
    if (l == r) return new Node(value, NULL, NULL);
    int mid = (l+r)>>1;
    Node *q = new Node(
        0,
        update(getLeft(p), l, mid),
        update(getRight(p), mid+1, r)
    );
    q->sum = getSum(getLeft(q)) + getSum(getRight(q));
    return q;
}


// number of visited (attacked) nodes from year of node a+1 ---> node b
int get(Node* a, Node* b, int l, int r) {
    if (l > r || l > posRight || r < posLeft) return 0;
    if (posLeft <= l && r <= posRight)
        return getSum(b) - getSum(a);
    int mid = (l+r)>>1;
    return get(getLeft(a), getLeft(b), l, mid) + get(getRight(a), getRight(b), mid+1, r);
}


// number of unvisited nodes from year y1 --> y2 of the path from u --> v
int f(int y1, int y2, int u, int v) {
    if (u == -1 || v == -1 || h[u] > h[v]) return 0;
    posLeft = start[u], posRight = start[v];
    return (h[v] - h[u] + 1) - get(root[y1-1], root[y2], 1, m);
}


int findKth(int y1, int y2, int k, int u, int root) {
    if (root == -1 || u == -1 || h[root] > h[u]) return -1;
    if (k == 1 && a[u] < y1) return u;
    for (int i = logN; i >= 0; --i) {
        int v = p[i][u];
        if (v < 0 || h[v] < h[root]) continue;
        int c = f(y1, y2, v, u);
        if (c < k) {
            k = k - c + (a[v] < y1);
            u = v;
        }
    }
    return p[0][u];
}


int solve(int i, int u, int v, int k, int y) {
    int r = lca(u, v), pu = p[0][u], pv = p[0][v];
    int cu = f(y+1, i, r, pu) - (a[r] <= y);    // not include r
    if (cu >= k)
        return findKth(y+1, i, k, pu, r);
    k -= max(cu, 0);
    int cv = f(y+1, i, r, pv) - (r == u && a[r] <= y);  // include r
    if (cv < k) return -1;
    return findKth(y+1, i, cv-k+1, pv, r);
}


int main() {
#ifdef DEBUG
    freopen("226E.in", "r", stdin);
    freopen("226E.out", "w", stdout);
#endif
    n = read();
    for (int i = 1; i <= n; ++i) {
        int r = read();
        e[r].push_back(i);
    }

    logN = 0;
    while ((1<<logN) <= n) ++logN;
    filla(ok, true);
    filla(a, 0);
    int u = e[0][0];
    p[0][u] = -1;
    h[u] = 1;
    m = 0;
    dfs(u);
    root[0] = build_tree(1, m);

    int nQ = read();
    for (int i = 1; i <= nQ; ++i) {
        int t = read();
        if (t == 1) {
            int c = read();
            a[c] = i;
            pos = start[c], value = 1;
            Node *tmp = update(root[i-1], 1, m);
            pos = finish[c], value = -1;
            root[i] = update(tmp, 1, m);
        }
        else {
            root[i] = root[i-1];
            int a, b, k, y;
            scanf("%d%d%d%d", &a, &b, &k, &y);
            printf("%d\n", solve(i, a, b, k, y));
        }
    }
    return 0;
}