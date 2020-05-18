/*
    ID: storm59061
    LANG: C++
    TASK: cowtour
*/
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
typedef pair<double, int> heap_element;

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
//#define heap_element pair<double, int>

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln() {  int x;  scanf("%d\n",&x);   return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

const int MAX_N = 155;
const double oo = 1000000000;

int n;
int x[MAX_N], y[MAX_N];
vector<pair<double, int> > e[MAX_N];
double d[MAX_N][MAX_N], f[MAX_N];

class cmp_heap_min {
public:
    bool operator() (const heap_element &x, const heap_element &y) const {
        return x.fr > y.fr;
    }
};
priority_queue<heap_element, vector<heap_element>, cmp_heap_min> heap;


double sqr(double x) {
    return x*x;
}

double dist(int i, int j) {
    return sqrt(sqr(x[i]-x[j]) + sqr(y[i]-y[j]));
}

void dijkstra(int s) {
    foru(i,1,n) d[s][i] = oo;
    while (!heap.empty()) heap.pop();
    heap.push(mp(d[s][s] = 0,s));
    while (!heap.empty()) {
        heap_element h = heap.top();
        heap.pop();
        int u = h.sc, sz = size(e[u]);
        if (h.fr > d[s][u]) continue;
        rep(i,sz) {
            int v = e[u][i].sc;
            double t = h.fr + e[u][i].fr;
            if (t < d[s][v]) {
                d[s][v] = t;
                heap.push(mp(t,v));
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
#endif
    read(n);
    foru(i,1,n) scanf("%d%d",&x[i],&y[i]);
    char s[MAX_N];
    foru(i,1,n) {
        scanf("%s",&s);
        foru(j,1,n)
            if (s[j-1] == '1')
                e[i].pb(mp(dist(i,j), j));
    }

    double res = 0;
    foru(i,1,n) {
        dijkstra(i);
        f[i] = 0;
        foru(j,1,n)
            if (d[i][j] < oo) {
                f[i] = max(f[i], d[i][j]);
            }
        res = max(res, f[i]);
    }

    double t = oo;
    foru(u,1,n)
        foru(v,1,n)
            if (d[u][v] == oo)
                t = min(t, f[u] + f[v] + dist(u,v));
    printf("%.6f\n",max(res,t));
    return 0;
}
