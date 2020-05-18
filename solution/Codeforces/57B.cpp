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

const int MAX_N = 100005;

int n, m, k;
int a[MAX_N], b[MAX_N], c[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("57B.in", "r", stdin);
    freopen("57B.out", "w", stdout);
#endif
    scanf("%d%d%d",&n,&m,&k);
    rep(i,m) scanf("%d%d%d",&a[i],&b[i],&c[i]);
    ll res = 0;
    rep(id, k) {
        int x = read();
        rep(i, m)
            if (a[i] <= x && x <= b[i])
                res += ll(x-a[i]+c[i]);
    }
    cout << res;
    return 0;
}
