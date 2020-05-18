/*
    ID: storm59061
    LANG: C++
    TASK: holstein
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


int main() {
#ifndef ONLINE_JUDGE
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
#endif
    int nV = read();
    int v[30];
    rep(i,nV) scanf("%d",&v[i]);
    int nF = read();
    int f[20][30];
    rep(i,nF)
        rep(j,nV) scanf("%d",&f[i][j]);

    int nL = 1e9;
    int tmp[20], list[20];
    rep(mask,1<<nF) {
        int c = 0;
        int sum[30] = {0};
        rep(i,nF)
            if (mask&(1<<i)) {
                tmp[c++] = i;
                rep(j,nV) sum[j] += f[i][j];
            }
        if (c >= nL) continue;
        bool ok = true;
        rep(i,nV)
            if (sum[i] < v[i]) {
                ok = false;
                break;
            }
        if (!ok) continue;
        nL = c;
        rep(i,c) list[i] = tmp[i];
    }

    printf("%d ",nL);
    rep(i,nL-1) printf("%d ",list[i]+1);
    printf("%d\n",list[nL-1]+1);
    return 0;
}
