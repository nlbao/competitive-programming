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

const int MAX_N = 50004;

int n;
ll sum;
ll a[MAX_N], value[MAX_N];
ll res_0[MAX_N], res[MAX_N];
vii b;

ll cal_pos(int i, ll x) {
    ll res = 0;
    if (i > 1) res += abs(x-a[i-1]);
    if (i < n) res += abs(x-a[i+1]);
    return res;
}

ll cal_change(int i, int j) {
    if (i == j) return 0;
    if (i > j) return cal_change(j, i);

    if (j-i == 1) {
        ll res = 0;
        if (i > 1) res += abs(a[j] - a[i-1]) - abs(a[i] - a[i-1]);
        if (j < n) res += abs(a[i] - a[j+1]) - abs(a[j] - a[j+1]);
        return res;
    }

    ll res = -(value[i] + value[j]);
    res += cal_pos(i, a[j]) + cal_pos(j, a[i]);
    return res;
}

void solve_0() {
    foru(i, 1, n) {
        res_0[i] = sum;
        foru(j, 1, n) {
            res_0[i] = min(res_0[i], sum + cal_change(i,j));
        }

    }
    foru(i, 1, n) printf("%lld ", res_0[i]);
    printf("\n\n");
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("L.in", "r", stdin);
    freopen("L.out", "w", stdout);
#endif
    sum = 0;
    read(n);
    foru(i, 1, n) {
        a[i] = read();
        if (i > 1) sum += abs(a[i]-a[i-1]);
    }

    foru(i, 1, n)
        value[i] = cal_pos(i, a[i]);

    //solve_0();

    foru(i, 1, n) {
        b.pb(mp(a[i], i));
        res[i] = sum;
    }
    sort(all(b));

    rep(i, n) {
        int x = b[i].sc;
        foru(j, max(0, i-500), min(n-1, i+500))
            res[x] = min(res[x], sum + cal_change(x, b[j].sc));
        rep(id, 500) {
            int j = rand()%n;
            res[x] = min(res[x], sum + cal_change(x, b[j].sc));
        }
    }

    foru(i, 1, n) printf("%lld ", res[i]);
    printf("\n");
    return 0;
}
