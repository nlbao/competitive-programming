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

const int MAX_N = 1503;
const ll oo = 1000000000000000000LL;

int n, m;
ll f[MAX_N], l[MAX_N], r[MAX_N], s[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("46E.in", "r", stdin);
    freopen("46E.out", "w", stdout);
#endif
    scanf("%d%d", &n, &m);
    s[0] = 0;
    fill(l, 0);
    fill(r, 0);
    l[0] = r[m+1] = -oo;
    foru(i, 1, n) {
        foru(j, 1, m) {
            f[j] = -oo;
            s[j] = s[j-1] + ll(read());
            if (i%2 == 0) f[j] = r[j+1] + s[j];
            else f[j] = l[j-1] + s[j];
        }
        foru(j, 1, m) l[j] = max(l[j-1], f[j]);
        ford(j, m, 1) r[j] = max(r[j+1], f[j]);
    }
    ll res = -oo;
    foru(i,1,m) res = max(res, f[i]);
    cout << res;
    return 0;
}
