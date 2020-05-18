#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
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

const int MAX_N = 17;

int n, k, res;
int a[MAX_N][MAX_N], b[MAX_N][MAX_N];
int f[MAX_N];


int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


bool check(int m, int k, int limit) {
    int pos = 1;
    rep(turn,k+1) {
        int old = pos;
        fill(f,0);
        while (pos <= n) {
            bool ck = true;
            foru(i,1,m)
                if (f[i]+b[i][pos] > limit) {
                    ck = false;
                    break;
                }
            if (!ck) break;
            foru(i,1,m) f[i] += b[i][pos];
            ++pos;
        }
        if (pos > n) return true;
        if (pos == old) return false;
    }
    return pos > n;
}

void solve(int m, int k) {
    k = min(k,n-1);
    int l = 0, r = res-1;
    while (l <= r) {
        int mid = (l+r)>>1;
        if (check(m,k,mid)) {
            res = mid;
            r = mid-1;
        }
        else l = mid+1;
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("partition.in", "r", stdin);
    freopen("partition.out", "w", stdout);
#endif
    scanf("%d%d",&n,&k);
    res = 0;
    foru(i,1,n)
        foru(j,1,n) res += read(a[i][j]);

    int limit = min(k,n-1);
    rep(mask,1<<limit) {
        int m = 1;
        fill(b,0);
        foru(i,1,n) b[1][i] = a[1][i];
        foru(i,1,n-1) {
            if ((mask>>(i-1))&1) ++m;
            foru(j,1,n) b[m][j] += a[i+1][j];
        }
        solve(m, k-(m-1));
    }
    cout << res;
    return 0;
}
