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

const int MAX_N = 3*100005;

int n, a, b, id, point;
int x[MAX_N], y[MAX_N], len[MAX_N];
int f[4*MAX_N], query[MAX_N];
map<int, int> q;
vi lst;

int fmin(int i, int j) {
    return len[i]<len[j]?i:j;
}

void update(int k, int l, int r) {
    if (l > r || l > b || r < a) return;
    //cout << k << "     " << l << " " << r <<"             " << f[k] << "            " << a << " " << b << endl;
    if (a <= l && r <= b) {
        f[k] = fmin(f[k], id);
        return;
    }

    int mid = (l+r)>>1;
    update(k<<1, l, mid);
    update((k<<1)+1, mid+1, r);
}

int get(int k, int l, int r) {
    if (l > r || l > point || r < point) return 0;
    //cout << "get  " << k << "    " << l << " " << r << "             " << f[k] << endl;
    if (l == r) return f[k];
    int mid = (l+r)>>1;
    int res = fmin(get(k<<1, l, mid), get((k<<1)+1, mid+1, r));
    return fmin(res, f[k]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("G.in", "r", stdin);
    freopen("G.out", "w", stdout);
#endif
    int n = read();
    foru(i, 1, n) {
        scanf("%d%d", &x[i], &y[i]);
        len[i] = y[i]-x[i];
        lst.pb(x[i]);
        lst.pb(y[i]);
    }
    int m = read();
    rep(i, m) {
        scanf("%d", &query[i]);
        lst.pb(query[i]);
    }

    int c = 0, limit = 2*n+m+1;
    sort(all(lst));
    rep(i, limit)
        if (q.find(lst[i]) == q.end())
            q[lst[i]] = ++c;

    fill(f, 0);
    len[0] = 2000000000;
    foru(i, 1, n) {
        id = i;
        a = q[x[i]], b = q[y[i]];
        update(1, 1, limit);
    }

    rep(i, m) {
        point = q[query[i]];
        int res = get(1, 1, limit);
        if (res < 1) res = -1;
        printf("%d\n", res);
    }
    return 0;
}
