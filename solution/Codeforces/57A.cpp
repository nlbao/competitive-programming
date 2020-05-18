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


int n, x[2], y[2];
int a[4], b[4];

int dist(int i, int j) {
    return abs(x[i]-a[j]) + abs(y[i]-b[j]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("57A.in", "r", stdin);
    freopen("57A.out", "w", stdout);
#endif
    scanf("%d",&n);
    rep(i,2) scanf("%d%d",&x[i],&y[i]);
    a[0] = a[1] = 0;
    a[2] = a[3] = n;
    b[0] = b[2] = 0;
    b[1] = b[3] = n;

    int res = n*n;
    rep(i,4)
            res = min(res, dist(0, i) + dist(1, i));
    if (x[0] == x[1] && (x[0] == 0 || x[0] == n)) res = min(res, abs(y[0]-y[1]));
    if (y[0] == y[1] && (y[0] == 0 || y[0] == n)) res = min(res, abs(x[0]-x[1]));
    cout << res;
    return 0;
}
