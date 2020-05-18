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

const int MAX_N = 40004;
const int MAX_M = 100005;

int n[2], m, idF, u, v, newValue, res = 0;
int f[2][4*MAX_N];
int value[2][MAX_N], head[2][MAX_N];
int pos[2][MAX_M];
vii e[2][MAX_N];


int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


void update(int k, int l, int r) {
    if (l > r || l > v || r < u) return;
    if (u <= l && r <= v) {
        f[idF][k] = max(f[idF][k], newValue);
        return;
    }
    int mid = (l+r)>>1;
    int left = k<<1, right = left+1;
    update(left,l,mid);
    update(right,mid+1,r);
    f[idF][k] = max(f[idF][left], f[idF][right]);
}

int get(int k, int l, int r) {
    if (l > r || l > v || r < u) return 0;
    if (u <= l && r <= v) return f[idF][k];
    int mid = (l+r)>>1;
    return max(get(k<<1,l,mid), get((k<<1)+1,mid+1,r));
}

void upF(int id, int l, int r, int value) {
    if (l > r) return;
    idF = id;
    u = l;  v = r;
    newValue = value;
    update(1,1,head[id][n[id]+1]);
}

int getF(int id, int l, int r) {
    if (l > r) return 0;
    idF = id;
    u = l;  v = r;
    return get(1,1,head[id][n[id]+1]);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("route.in", "r", stdin);
    freopen("route.out", "w", stdout);
#endif
    scanf("%d%d%d",&n[0],&n[1],&m);
    rep(id,2) foru(i,1,n[id]) read(value[id][i]);
    foru(i,1,m) {
        int x = read(), y = read();
        e[0][x].pb(mp(y,i));
        e[1][y].pb(mp(x,i));
    }

    fill(head,0);
    rep(id,2) foru(u,1,n[id]+1) {
        sort(all(e[id][u]));
        head[id][u+1] = head[id][u];
        for(int i = 0, sz = size(e[id][u]); i < sz; ++i)
            pos[id][e[id][u][i].sc] = ++head[id][u+1];
    }

    fill(f,0);
    foru(u,1,n[0])
        for(int t = 0, sz = size(e[0][u]); t < sz; ++t) {
            int v = e[0][u][t].fr, i = e[0][u][t].sc;
            //(0;i) v --> u
            int tmp = max(value[1][v], getF(1, head[1][v]+1, pos[1][i]-1)) + value[0][u];
            //upF(0, pos[0][i], head[0][u+1], tmp);
            upF(0, pos[0][i], pos[0][i], tmp);
            res = max(res, tmp);

            //(1;i) u --> v
            tmp = max(value[0][u], getF(0, head[0][u]+1, pos[0][i]-1)) + value[1][v];
            //upF(1, pos[1][i], head[1][v+1], tmp);
            upF(1, pos[1][i], pos[1][i], tmp);
            res = max(res, tmp);
        }
    cout << res;
    return 0;
}
