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

const int MAX_N = 10004;

int n, m, c;
vector<pair<int,pii> > e;
vi a;
int p[MAX_N];
bool ok[MAX_N];

void enter() {
    e.clear();
    scanf("%d%d%d", &n, &m, &c);
    rep(i, m) {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        e.pb(mp(w, mp(x,y)));
    }
}

int get_root(int u) {
    if (p[u] < 0) return u;
    return p[u] = get_root(p[u]);
}

void solve() {
    sort(all(e));
    a.clear();
    foru(i,1,n) p[i] = -1;
    ford(i, m-1, 0) {
        int r1 = get_root(e[i].sc.fr), r2 = get_root(e[i].sc.sc);
        if (r1 != r2) {
            p[r1] = r2;
            p[r2] += p[r2];
        }
        else a.pb(e[i].fr);
    }
    sort(all(a));

    int k = 0;
    fill(ok, true);
    foru(i,1,n) {
        int r = get_root(i);
        if (ok[r]) {
            ++k;
            ok[r] = false;
        }
    }

    int i = 0, szA = sz(a);
    int res = 0, nA = 0, nC = 0;
    rep(t, k-1)
        if (i < szA && a[i] <= c) {
            res += a[i++];
            ++nA;
        }
        else {
            res += c;
            ++nC;
        }
    printf("%d %d %d\n", nC, nA, res);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id, nTest) {
        enter();
        solve();
    }
    return 0;
}
