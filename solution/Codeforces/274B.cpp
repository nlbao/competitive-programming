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

const int MAX_N = 100005;

int n;
vi e[MAX_N];
int value[MAX_N], a[MAX_N], sz[MAX_N], p[MAX_N];

ll getH(int x) {   return ll(value[x])+ll(a[x]);   }
struct cmpMin { bool operator()(const int& l, const int& r) { return getH(l) > getH(r);   } };
struct cmpMax { bool operator()(const int& l, const int& r) { return getH(l) < getH(r);   } };
priority_queue<int, vector<int>, cmpMin> hmin;
priority_queue<int, vector<int>, cmpMax> hmax;


int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }



void dfs(int u) {
    sz[u] = 0;
    for(int c = size(e[u]), i = 0; i < c; ++i) {
        int v = e[u][i];
        if (v == p[u]) continue;
        p[v] = u;
        ++sz[u];
        dfs(v);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("274B.in", "r", stdin);
    freopen("274B.out", "w", stdout);
#endif
    read(n);
    rep(i,n) {
        int x = read(), y = read();
        e[x].pb(y);
        e[y].pb(x);
    }
    foru(i,1,n) read(value[i]);

    p[1] = 0;
    dfs(1);
    fill(a,0);
    foru(i,1,n) if (!sz[i])
        if (getH(i) > 0) hmin.push(i);
        else hmax.push(i);

    while(!hmin.empty() || !hmax.empty()) {
        while (!hmin.empty()) {
            int u =
        }
    }

    return 0;
}
