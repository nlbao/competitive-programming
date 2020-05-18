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
#include <stdlib.h>
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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

const int MAX_N = 1003;
const int MAX_M = 102;
const int MAX_F = 777;
const ll BASE = 10007LL;

int n, m, res;
char a[MAX_N], b[MAX_M];
string tmp;
int kmp[MAX_M];
int f[MAX_F+4][MAX_N], id[MAX_F+4], value[MAX_F+4];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


void init(int x) {
    id[x] = x;
    int c = 0;
    tmp = "";
    rep(i,n) if (f[x][i]) {
        ++c;
        tmp += a[i];
    }
    for(int i = 0, j = 0; i < c; ++i) {
        while (j && tmp[i] != b[j]) j = kmp[j-1];
        if (tmp[i] == b[j]) ++j;
        if (j == m) {
            value[x] = MAX_N+MAX_M;
            return;
        }
    }
    value[x] = n-c;
}

void qsort(int l, int r) {
    if (l >= r) return;
    int p = value[id[(l+r)>>1]];
    int i = l, j = r;
    while (i <= j) {
        while (value[id[i]] < p) ++i;
        while (value[id[j]] > p) --j;
        if (i <= j) {
            int t = id[i];
            id[i] = id[j];
            id[j] = t;
            ++i;    --j;
        }
    }
    qsort(l,j);
    qsort(i,r);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("necklace.in", "r", stdin);
    freopen("necklace.out", "w", stdout);
#endif
    scanf("%s%s",&a,&b);
    n = strlen(a);
    m = strlen(b);
    if (n == m) {
        if (a == b) cout << 1;
        else cout << 0;
        return 0;
    }


    kmp[0] = 0;
    for(int i = 1, j = 0; i < m; ++i) {
        while (j && b[i] != b[j]) j = kmp[j-1];
        if (b[i] == b[j]) ++j;
        kmp[i] = j;
    }


    res = n-m+1;
    srand(time(NULL));
    rep(i,MAX_F) {
        rep(j,n) f[i][j] = rand()%2 ;
        init(i);
    }
    qsort(0,MAX_F-1);
    res = min(res,value[id[0]]);

    for(int i = 0; i < 44 && res; ++i) {
        int m = MAX_F>>1;
        foru(i,m,MAX_F-1) {
            int p1 = rand()%m, p2 = p1;
            while (p2 == p1) p2 = rand()%m;
            rep(j,n/2) f[i][j] = f[p1][j];
            foru(j,n/2,n-1) f[i][j] = f[p2][j];
            //if (rand()%4 == 0) {
                int j = rand()%n;
                f[i][j] = 1-f[i][j];
            //}
        }

        rep(i,m) id[i] = i;
        foru(i,m,MAX_F-1) init(i);
        qsort(0,MAX_F-1);
        res = min(res,value[id[0]]);
    }
    cout << res;
    return 0;
}
