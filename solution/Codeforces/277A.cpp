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

int n, m;
vi e[MAX_N];
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

void dfs(int u) {
    if (!ok[u]) return;
    ok[u] = false;
    for(int sz = size(e[u]), i = 0; i < sz; ++i) dfs(e[u][i]);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("277A.in", "r", stdin);
    freopen("277A.out", "w", stdout);
#endif
    int n = read(), m = read(), c = 0;
    foru(i,1,n) {
        int k = read();
        rep(id,k) {
            int j = read();
            e[i].pb(j+n);
            e[j+n].pb(i);
        }
        if (!k) ++c;
    }

    fill(ok,true);
    int res = -1;
    foru(i,1,n) if (ok[i]) {
        dfs(i);
        ++res;
    }
    if (c==n) ++res;
    cout<<res;
    return 0;
}
