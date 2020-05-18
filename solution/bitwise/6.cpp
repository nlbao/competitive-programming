#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
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

const int MAX_N = 1003;
const int MAX_M = (MAX_N*MAX_N)>>1;
const int oo = 1000000000;

int n;
vi e[MAX_N];
int f[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
void read(int &x) {  scanf("%d",&x);    }
void readln(int &x) {   scanf("%d\n",&x);   }


void topo_sort() {

}

void dfs(int u) {
    f[u] = oo;
    if (u == n) {
        f[u] = 0;
        return;
    }
    if (e[u].empty()) return;
    for(int i = 0, sz = size(e[u]); i < sz; ++i) {
        int v = e[u][i];
        if (f[v] == -1) dfs(v);
        if (i) f[u] = min(f[u], f[v]+1);
        else f[u] = min(f[u], f[v]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    //freopen("6.in", "r", stdin);
    //freopen("6.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id,nTest) {
        read(n);
        foru(i,1,n) e[i].clear();
        int m = read();
        rep(i,m) {
            int x = read(), y = read();
            e[x].pb(y);
        }

        foru(i,1,n) {
            sort(all(e[i]));
            f[i] = -1;
        }
        topo_sort();
        dfs(1);
        if (f[1] >= oo) printf("-1");
        else printf("%d",f[1]);
        if (test_id < nTest-1) printf("\n");
    }
    return 0;
}
