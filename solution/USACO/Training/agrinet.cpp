/*
    ID: storm59061
    LANG: C++
    TASK: agrinet
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

const int MAX_N = 102;

int n;
int p[MAX_N];
vector<pair<int,pii> > e;

int get_root(int u) {
    if (p[u] < 0) return u;
    return p[u] = get_root(p[u]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("agrinet.in", "r", stdin);
    freopen("agrinet.out", "w", stdout);
#endif
    scanf("%d",&n);
    foru(i,1,n)
        foru(j,1,n) {
            int x = read();
            if (x > 0) e.pb(mp(x,mp(i,j)));
        }

    int res = 0;
    rep(i,n) p[i] = -1;
    sort(all(e));
    int sz = size(e);
    rep(i,sz) {
        int u = e[i].sc.fr, v = e[i].sc.sc;
        int r1 = get_root(u), r2 = get_root(v);
        if (r1 != r2) {
            res += e[i].fr;
            p[r1] = r2;
        }
    }
    printf("%d\n",res);
    return 0;
}
