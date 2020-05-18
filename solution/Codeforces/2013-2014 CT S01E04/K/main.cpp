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

const int MAX_N = 102;
const int MAX_P = 1000006;
const int MAX_M = 8;
const int MAX_X = 1<<MAX_M;
const int oo = 2000000009;

int n, P, m;
int a[MAX_N], v[MAX_N];
int p[MAX_M];
int f[MAX_N][MAX_X];


int get_bit(int x, int i) {
    return x&(1<<i);
}

int set_bit(int &x, int i, bool one = true) {
    if (one) x |= (1<<i);
    else x &= ~(1<<i);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    int nTest = read();
rep(test_id, nTest) {
    scanf("%d%d", &n, &P);
    foru(i,1,n) scanf("%d",&a[i]);

    m = 0;
    for (int i = 2; i <= P; ++i)
        if (P%i == 0) {
            p[m++] = i;
            while (P%i == 0) P /= i;
        }

    foru(i,1,n) {
        v[i] = 0;
        rep(j, m)
            set_bit(v[i], j, a[i]%p[j] == 0);
    }

    rep(x, 1<<m) f[0][x] = oo;
    f[0][0] = 0;

    foru(i,1,n) {
        rep(x, 1<<m) {
            f[i][x] = oo;
            int sum = 0;
            ford(j,i-1,0) {
                sum += a[j+1];
                int y = 0, z = x;
                rep(k, m)
                    if (sum%p[k] == 0)
                        set_bit(z, k, false);

                if (f[j][z] < oo)
                    f[i][x] = min(f[i][x], f[j][z]+1);
            }
        }
        f[i][0] = 1;
    }

    int res = 1, nCut = 1;
    rep(x, 1<<m)
        if (f[n][x] < oo) {
            int d = 1;
            rep(i, m)
                if (get_bit(x, i)) d *= p[i];
            if (d > res) {
                res = d;
                nCut = f[n][x];
            }
            else if (d == res) nCut = min(nCut, f[n][x]);
        }
    printf("%d %d\n", res, nCut-1);
}
    return 0;
}
