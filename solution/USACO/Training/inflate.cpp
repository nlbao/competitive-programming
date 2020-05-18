/*
    ID: storm59061
    LANG: C++
    TASK: inflate
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

const int MAX_N = 10004;
const int MAX_M = 10004;

int n, m;
vii a;
int f[MAX_M];

int main() {
#ifndef ONLINE_JUDGE
    freopen("inflate.in", "r", stdin);
    freopen("inflate.out", "w", stdout);
#endif
    scanf("%d%d",&m,&n);
    rep(i,n) {
        int x = read(), y = read();
        a.pb(mp(y,x));
    }

    fill(f,0);
    sort(all(a));
    int sz = size(a);
    rep(i,sz) {
        int w = a[i].fr, v = a[i].sc;
        while (w <= m) {
            ford(x,m,w)
                f[x] = max(f[x], f[x-w]+v);
            w <<= 1;
            v <<= 1;
        }
    }

    int res = 0;
    rep(i,m+1) res = max(res, f[i]);
    printf("%d\n",res);
    return 0;
}
