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

const int MAX_N = 100005;

int n;
char s[MAX_N];
int a[MAX_N], f[MAX_N];
int pre[MAX_N], pnext[MAX_N];
vi e[2];

bool check(int u, int v) {
    if (u < 1 || u > n) return false;
    if (v < 1 || v > n) return false;
    return a[u] == 0 && a[v] == 1;
}

ll get(int i) {
    if (i < 1 || i > n) return 0;
    return f[i] + get(i - (i & (-i)));
}

void update(int i) {
    if (i < 1 || i > n) return;
    ++f[i];
    update(i + (i & (-i)));
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("PPLUCKY.in", "r", stdin);
    freopen("PPLUCKY.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id, nTest) {
        scanf("%d", &n);
        scanf("%s", &s);
        rep(i, n) a[i+1] = (s[i] == '7');
        rep(i, n+4) {
            pnext[i] = i+1;
            pre[i] = i-1;
        }
        a[0] = a[n+1] = a[n+2] = -1;
        //cout << n << " " << s << endl;
        ll res = 0;
        fill(f, 0);
        rep(i, 2) e[i].clear();
        foru(i, 1, n-1)
            if (a[i+1]-a[i] == 1)
                e[0].pb(i);

        for (int t = 0; ; t = 1-t) {
            int szE = sz(e[t]), tt = 1-t;
            if (!szE) break;
            e[tt].clear();

            rep(i, szE) {
                int x = e[t][i], u = pre[x], v = pnext[pnext[x]];
                res += x-get(x-1);
                if (check(u, v)) e[tt].pb(u);
                pnext[u] = v;
                pre[v] = u;
            }

            rep(i, szE) {
                update(e[t][i]);
                update(e[t][i]+1);
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
