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

const int MAX_N = 100005;

int deg[MAX_N], c[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("292B.in", "r", stdin);
    freopen("292B.out", "w", stdout);
#endif
    int n = read(), m = read();
    fill(deg,0);
    rep(i,m) {
        int x = read(), y = read();
        ++deg[x];
        ++deg[y];
    }
    fill(c,0);
    foru(i,1,n) ++c[deg[i]];

    if (c[1] == 2 && c[2] == n-2) printf("bus topology");
    else if (c[2] == n) printf("ring topology");
    else if (c[1] == n-1 && c[n-1] == 1) printf("star topology");
    else printf("unknown topology");
    return 0;
}
