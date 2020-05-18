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
#define sz(a) int(a.size())
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

const int MAX_N = 111;

int f[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("PPTEST.in", "r", stdin);
    freopen("PPTEST.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id, nTest) {
        int n = read(), w = read();
        fill(f, 0);
        rep(i, n) {
            int c, p, t;
            scanf("%d%d%d", &c, &p, &t);
            c *= p;
            ford(x, w, t)
                f[x] = max(f[x], f[x-t]+c);
        }
        int res = 0;
        rep(i, w+1) res = max(res, f[i]);
        printf("%d\n", res);
    }
    return 0;
}
