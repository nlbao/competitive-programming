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


namespace fastIO {
    const size_t amount = 16;
    static char buffer[1<<16];
    static char* dataEnd = buffer + sizeof(buffer);
    static const char* pos = dataEnd;

    inline void readAhead() {
        size_t remaining = dataEnd - pos;
        if (remaining < amount) {
            memmove(buffer, pos, remaining);
            size_t sz = fread(buffer + remaining, 1, sizeof(buffer) - remaining, stdin);
            pos = buffer;
            dataEnd = buffer + remaining + sz;
            if (dataEnd != buffer + sizeof(buffer))
                *dataEnd = 0;
        }
    }

    inline int readInt() {
        readAhead();
        int x = 0;
        bool neg = false;
        if (*pos == '-') {
            ++pos;
            neg = true;
        }
        while (*pos < '0' || *pos > '9') ++pos;
        while (*pos >= '0' && *pos <= '9') {
            x *= 10;
            x += *pos - '0';
            ++pos;
        }
        return neg ? -x : x;
    }
};

const int MAX_N = int(1e5)+5;
const int MAX_LOG = 19;

struct Node {
    int cnt;
    Node *pLeft, *pRight;
    Node(int cnt, Node* pLeft, Node* pRight): cnt(cnt), pLeft(pLeft), pRight(pRight) {};
};

int n, nQ, maxA, logN;
int a[MAX_N], h[MAX_N], p[MAX_LOG][MAX_N];
vector<int> e[MAX_N];
map<int, int> id, r_id;
Node* root[MAX_N];
bool ok[MAX_N];


inline int getCnt(Node* p) {   return p ? p->cnt : 0;  }
inline Node* getLeft(Node* p) {    return p ? p->pLeft : NULL;  }
inline Node* getRight(Node* p) {    return p ? p->pRight : NULL;    }


Node* update(Node* p, int l, int r, int value) {
    if (l > r) return NULL;
    if (l > value || r < value) return p;
    if (l == r) return new Node(getCnt(p)+1, NULL, NULL);
    int mid = (l+r)>>1;
    return new Node(
        getCnt(p)+1,
        update(getLeft(p), l, mid, value),
        update(getRight(p), mid+1, r, value)
    );
}


int get(Node* a, Node* b, Node* c, Node* d, int l, int r, int k) {
    if (l > r) return -1;
    if (l == r) return l;
    int mid = (l+r)>>1;
    int cnt = getCnt(getLeft(b)) + getCnt(getLeft(a)) - getCnt(getLeft(c)) - getCnt(getLeft(d));
    if (k <= cnt) return get(getLeft(a), getLeft(b), getLeft(c), getLeft(d), l, mid, k);
    return get(getRight(a), getRight(b), getRight(c), getRight(d), mid+1, r, k-cnt);
}


void dfs(int u) {
    ok[u] = false;
    int v = p[0][u];
    root[u] = update(root[v > -1 ? v : 0], 1, maxA, id[a[u]]);

    for (int i = 1; i <= logN; ++i)
        if (h[u] - (1<<i) > 0) p[i][u] = p[i-1][p[i-1][u]];
        else p[i][u] = -1;

    for (int i = 0, sz = (int)e[u].size(); i < sz; ++i) {
        v = e[u][i];
        if (ok[v]) {
            p[0][v] = u;
            h[v] = h[u] + 1;
            dfs(v);
        }
    }
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


int main() {
#ifdef DEBUG
    freopen("COT.in", "r", stdin);
    freopen("COT.out", "w", stdout);
#endif
    scanf("%d%d", &n, &nQ);
    for (int i = 1; i <= n; ++i) {
        a[i] = fastIO::readInt();
        id[a[i]];
    }
    for (int i = 0; i < n-1; ++i) {
        int x, y;
        // scanf("%d%d", &x, &y);
        x = fastIO::readInt();
        y = fastIO::readInt();
        e[x].push_back(y);
        e[y].push_back(x);
    }

    maxA = 0;
    tr(id, it) {
        it->second = ++maxA;
        r_id[maxA] = it->first;
    }

    logN = 0;
    while ((1<<logN) <= n) ++logN;
    root[0] = new Node(0, NULL, NULL);
    filla(ok, true);
    p[0][1] = -1;
    h[1] = 1;
    dfs(1);

    while (nQ--) {
        int u, v, k;
        // scanf("%d%d%d", &u, &v, &k);
        u = fastIO::readInt();
        v = fastIO::readInt();
        k = fastIO::readInt();
        int r = lca(u, v), rr = p[0][r];
        if (rr < 0) rr = 0;
        int ans = get(root[u], root[v], root[r], root[rr], 1, maxA, k);
        printf("%d\n", r_id[ans]);
    }
    return 0;
}