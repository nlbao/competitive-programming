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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

const int MAX_N = 1010;

int n, root;
ll p[MAX_N], s[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

ll get_s(int i, int j) {
    if (i > j) return 0;
    if (i == 0) return s[j];
    return s[j]-s[i-1];
}

ll solve() {
    sort(p,p+n+1);
    rep(i,n+1)
        if (p[i] == 0) {
            root = i;
            break;
        }
    s[0] = abs(p[0]);
    foru(i,1,n) s[i] = s[i-1] + abs(p[i]);

    ll t1 = get_s(0,root-1), t2 = get_s(root+1,n);
    ll res = min(t1 + ll(n-root)*2*abs(p[0]) + t2, t2 + ll(root)*2*abs(p[n]) + t1);
    foru(i,0,root) {
        ll sum = get_s(i,root-1);
        sum += ll(n-root)*2*abs(p[i]) + get_s(root+1,n);
        sum += ll(i)*2*(abs(p[i])+abs(p[n])) + get_s(0,i-1);
        if (sum < res) res = sum;
    }
    foru(i,0,root)
        foru(j,root,n) {
            ll sum = get_s(i,root);
            sum += ll(j-root)*2*abs(p[i]) + get_s(root+1,j);
            sum += ll(i)*2*(abs(p[i])+abs(p[j])) + get_s(0,i-1);
            sum += ll(n-j)*2*(abs(p[i])+abs(p[j])+abs(p[0]) )+ get_s(j+1,n);
            if (sum < res) res = sum;
        }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("cowrun.in", "r", stdin);
    freopen("cowrun.out", "w", stdout);
#endif
    read(n);
    rep(i,n) p[i] = read();
    p[n] = 0;
    ll res = solve();
    rep(i,n+1) p[i] = -p[i];
    res = min(res,solve());
    cout << res;
    return 0;
}
