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

const int MAX_N = int(1e5)+5;

struct Node {
    int cnt;
    Node *pLeft, *pRight;
    Node(int cnt, Node* pLeft, Node* pRight): cnt(cnt), pLeft(pLeft), pRight(pRight) {};
};

int n, nQ, maxA;
int a[MAX_N];
map<int, int> id, r_id;
Node* root[MAX_N];


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


int get(Node* a, Node* b, int l, int r, int k) {
    if (l > r) return -1;
    if (l == r) return l;
    int mid = (l+r)>>1;
    int cnt = getCnt(getLeft(b)) - getCnt(getLeft(a));
    if (k <= cnt) return get(getLeft(a), getLeft(b), l, mid, k);
    return get(getRight(a), getRight(b), mid+1, r, k-cnt);
}


int main() {
#ifdef DEBUG
    freopen("MKTHNUM.in", "r", stdin);
    freopen("MKTHNUM.out", "w", stdout);
#endif
    scanf("%d%d", &n, &nQ);
    for (int i = 1; i <= n; ++i) {
        a[i] = read();
        id[a[i]];
    }
    maxA = 0;
    tr(id, it) {
        it->second = ++maxA;
        r_id[maxA] = it->first;
    }

    root[0] = new Node(0, NULL, NULL);
    for (int i = 1; i <= n; ++i)
        root[i] = update(root[i-1], 1, maxA, id[a[i]]);

    while (nQ--) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int ans = get(root[l-1], root[r], 1, maxA, k);
        printf("%d\n", r_id[ans]);
    }
    return 0;
}