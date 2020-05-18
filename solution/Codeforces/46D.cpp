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

int n, L, b, f;
int a[4*MAX_N], c[4*MAX_N];
int pos[111], len[111];

void update(int k, int l, int r, int u, int v) {
    if (l > r || u > v || l > v || r < u) return;
    if (u <= l && r <= v) {
        a[k] = !a[k];
        return;
    }
    int mid = (l+r)>>1;
    int left = k<<1, right = left+1;
    update(left, l, mid, u, v);
    update(right, mid+1, r, u, v);
    c[k] = a[left] && a[right] && c[left] && c[right];
}

bool get(int k, int l, int r, int u, int v) {
    if (l > r || u > v || l > v || r < u) return true;
    if (!a[k]) return false;
    if (u <= l && r <= v) return a[k] && c[k];
    int mid = (l+r)>>1;
    if (!get(k<<1, l, mid, u, v)) return false;
    if (!get((k<<1)+1, mid+1, r, u, v)) return false;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("46D.in", "r", stdin);
    freopen("46D.out", "w", stdout);
#endif
    scanf("%d%d%d%d", &L, &b, &f, &n);
    fill(a, true);
    fill(c, true);

    foru(i,1,n) {
        int x = read(), y = read();
        if (x == 1) {
            len[i] = y;
            pos[i] = -1;
            rep(p, L-y+1)
                if (get(1, 1, L, max(p-b+1, 0), min(p+y+f-1, L))) {
                    pos[i] = p;
                    update(1, 1, L, p, p+y);
                    break;
                }
            printf("%d\n", pos[i]);
        }
        else
            update(1, 1, L, pos[y], pos[y]+len[y]);
    }
    return 0;
}
