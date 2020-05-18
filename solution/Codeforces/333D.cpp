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

const int MAX_N = 1003;

int n, m;
int a[MAX_N][MAX_N];
bool ok[MAX_N][MAX_N];

bool find(int value) {
    fill(ok,false);
    foru(i,1,n) {
        vi p;
        foru(j,1,m)
            if (a[i][j] >= value) p.pb(j);
        int sz = size(p);
        rep(j,sz)
            foru(k,j+1,sz-1) {
                if (ok[p[j]][p[k]]) return true;
                ok[p[j]][p[k]] = true;
            }
    }
    return false;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("333D.in", "r", stdin);
    freopen("333D.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    foru(i,1,n) foru(j,1,m) scanf("%d",&a[i][j]);
    int res = 0, l = 0, r = 1e9;
    while (l <= r) {
        int mid = (l+r)>>1;
        if (find(mid)) {
            res = mid;
            l = mid+1;
        }
        else r = mid-1;
    }
    cout << res;
    return 0;
}
