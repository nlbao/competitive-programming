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

const int MAX_N = 111;
const int MAX_M = MAX_N*MAX_N/2;

pair<int, pii> e[MAX_M];
bool ok[MAX_N];
int p[MAX_N];

int get_root(int u) {
    if (p[u] == u) return u;
    return p[u] = get_root(p[u]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif
    int n, k, m = 0;
    scanf("%d%d", &n, &k);
    fill(ok, false);
    rep(i, k) {
        int x = read();
        ok[x] = true;
    }

    foru(i, 1, n)
        foru(j, 1, n) {
            int x = read();
            if (j > i) e[m++] = mp(x, mp(i, j));
        }
    sort(e, e+m);

    int res = 0;
    foru(i, 1, n) p[i] = i;
    rep(i, m) {
        int x = get_root(e[i].sc.fr), y = get_root(e[i].sc.sc);
        if (!(ok[x] && ok[y])) {
            res += e[i].fr;
            if (ok[x]) swap(x, y);
            p[x] = y;
        }
    }
    printf("%d\n", res);
    return 0;
}
