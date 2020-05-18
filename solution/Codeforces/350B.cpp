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

int n, res, first;
int is_hotel[MAX_N], d[MAX_N], e[MAX_N], p[MAX_N];

void dfs(int u, int len) {
    if (len > res) {
        res = len;
        first = u;
    }
    int v = e[u];
    if (v && d[v] == 1) {
        p[v] = u;
        dfs(v, len+1);
    }
}

void print_res(int u) {
    if (!u) return;
    printf("%d ", u);
    print_res(p[u]);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("350B.in", "r", stdin);
    freopen("350B.out", "w", stdout);
#endif
    scanf("%d",&n);
    fill(d, 0);
    foru(i,1,n) scanf("%d", &is_hotel[i]);
    foru(i,1,n) {
        scanf("%d", &e[i]);
        ++d[e[i]];
    }

    res = first = 0;
    fill(p, 0);
    foru(i,1,n)
        if (is_hotel[i]) dfs(i, 1);
    printf("%d\n", res);
    print_res(first);
    return 0;
}
