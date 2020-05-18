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
// #pragma comment(linker, "/STACK:16777216")

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

const int MAX_N = 100005;
const int MAX_P = 20;

int n;
int a[MAX_N];
int f[MAX_P][MAX_N], sum[MAX_P][MAX_N];

void build_tree(int k, int l, int r) {
    if (l >= r) return;
    int mid = (l+r)>>1, p = a[mid];
    int x = l, y = mid+1;
    foru(i,l,r) {
        if (i == l) sum[k][i] = 0;
        else sum[k][i] = sum[k][i-1];
        if (f[k][i] <= p) {
            f[k+1][x++] = f[k][i];
            ++sum[k][i];
        }
        else
            f[k+1][y++] = f[k][i];
        if (sum[k][i] < 0) cout << "!!!! " << k << " " << i << "   " << sum[k][i] << endl;
    }
    build_tree(k+1, l, mid);
    build_tree(k+1, mid+1, r);
}

int get(int k, int l, int r, int u, int v, int pos) {
    if (l > r || u > v) return -1;
    if (l == r) return f[k][l];

    int mid = (l+r)>>1, s, ss;
    if (u == l) {
        s = 0;
        ss = sum[k][v];
    }
    else {
        s = sum[k][u - 1];
        ss = sum[k][v] - s;
    }

    if (pos <= ss) {
        int L = l + s;
        int R = l + sum[k][v] - 1;
        return get(k+1, l, mid, L, R, pos);
    }
    else {
        int L = mid + 1 - l + u - s;
        int R = mid + 1 - l + v - sum[k][v];
        return get(k+1, mid+1, r, L, R, pos - ss);
    }
}

int main() {
#ifdef DEBUG
    freopen("YPKTH.in", "r", stdin);
    freopen("YPKTH.out", "w", stdout);
#endif
    n = read();
    foru(i,1,n) scanf("%d",&a[i]);

    foru(i,1,n) f[0][i] = a[i];
    sort(a+1, a+1+n);
    fill(sum, 0);
    build_tree(0, 1, n);

    int q = read();
    rep(q_id, q) {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        int res = get(0, 1, n, l, r, k);
        printf("%d\n", res);
    }
    return 0;
}
