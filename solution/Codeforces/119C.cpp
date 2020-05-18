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

const int MAX_N = 52;
const int MAX_D = 102;

struct subject {
    int c, id;
    ll a, b;
    subject (ll aa, ll bb, int cc, int i) {
        a = aa;
        b = bb;
        c = cc;
        id = i;
    }
    bool operator < (const subject &x) const {
        return c < x.c;
    }
};

int n, m, p;
vector<subject> sub;
ll f[MAX_N][MAX_N][MAX_D];
int trace[MAX_N][MAX_N][MAX_D][2];
ll res = 0;
int ri, rj, rk;

void update(int i, int j, int k, int ii, int kk) {
    if (kk < 0 || kk > sub[ii].b-sub[ii].a || sub[i].c == sub[ii].c) return;
    ll tmp = f[ii][j-1][kk]+sub[i].a+ll(k);
    if (f[ii][j-1][kk] < 1 || tmp <= f[i][j][k]) return;
    f[i][j][k] = tmp;
    trace[i][j][k][0] = ii;
    trace[i][j][k][1] = kk;
}

void print_res(int i, int j, int k) {
    if (i < 1 || j < 1) return;
    print_res(trace[i][j][k][0], j-1, trace[i][j][k][1]);
    printf("%d %I64d\n", sub[i].id, sub[i].a+ll(k));
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("119C.in", "r", stdin);
    freopen("119C.out", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &p);
    sub.pb(subject(0,0,-1,0));
    foru(i,1,m) {
        ll a, b, c;
        scanf("%I64d%I64d%I64d", &a, &b, &c);
        sub.pb(subject(a, b, c, i));
    }

    sort(all(sub));

    fill(f, 0);
    fill(trace, 0);
    foru(i,1,m) {
        foru(k,0,sub[i].b-sub[i].a) {
            f[i][1][k] = sub[i].a+k;
            int j = 1;
            if (j == n && f[i][j][k] > res) {
                res = f[i][j][k];
                ri = i; rj = j; rk = k;
            }
        }
        foru(j,2,min(i,n))
            foru(k,0,sub[i].b-sub[i].a) {
                foru(ii,1,i-1) {
                    update(i,j,k, ii, sub[i].a+k-p-sub[ii].a);
                    if ((sub[i].a+k)%p == 0)
                        update(i,j,k, ii, (sub[i].a+k)/p-sub[ii].a);
                }
                if (j == n && f[i][j][k] > res) {
                    res = f[i][j][k];
                    ri = i; rj = j; rk = k;
                }
            }
    }

    if (res < 1) {
        cout << "NO";
        return 0;
    }

    cout << "YES" << endl;
    print_res(ri, rj, rk);
    return 0;
}
