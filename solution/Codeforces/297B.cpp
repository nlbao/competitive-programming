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

const int MAX_N = 200005;

int n, m, k;
map<int,int> a,b;
vi c,d;
int ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

string solve() {
    tr(a,it)
        rep(i,it->sc)
            c.pb(it->fr);
    tr(b,it)
        rep(i,it->sc)
            d.pb(it->fr);
    sort(all(c));
    sort(all(d));

    n = size(c);
    m = size(d);
    fill(ok,true);
    int i = n-1, j = m-1;
    while (i >= 0 && j >= 0)
        if (d[j] >= c[i]) {
            ok[i] = false;
            //cout << d[j] << " " << c[i] << endl;
            --i;    --j;
        }
        else --i;

    rep(i,n)
        if (ok[i]) return "YES";
    return "NO";
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("297B.in", "r", stdin);
    freopen("297B.out", "w", stdout);
#endif
    scanf("%d%d%d",&n,&m,&k);
    rep(i,n) {
        int x = read();
        if (a.find(x) == a.end()) a[x] = 1;
        else ++a[x];
    }
    rep(i,m) {
        int x = read();
        if (b.find(x) == b.end()) b[x] = 1;
        else ++b[x];
    }

    tr(a,it) {
        int v = it->fr;
        if (b.find(v) != b.end())
            if (b[v] >= a[v]) {
                b[v] -= a[v];
                a[v] = 0;
            }
            else {
                a[v] -= b[v];
                b[v] = 0;
            }
    }

    cout << solve();
    return 0;
}
