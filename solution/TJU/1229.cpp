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

const int MAX_N = 222;

int n;
int a[MAX_N], sz[MAX_N], f[MAX_N];
vi e[MAX_N];


int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

int dfs(int u) {
    int m = sz[u];
    rep(i,m) dfs(e[u][i]);
    rep(i,m) a[i] = f[e[u][i]];
    sort(a,a+m);
    f[u] = 1;
    rep(i,m) f[u] = max(f[u], a[i]+m-1-i);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("1229.in", "r", stdin);
    freopen("1229.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id,nTest) {
        scanf("%d",&n);
        rep(id,n) {
            int i = read();
            e[i].clear();
            read(sz[i]);
            rep(k,sz[i]) e[i].pb(read());
        }
        dfs(1);
        printf("%d\n",f[1]);
    }
    return 0;
}
