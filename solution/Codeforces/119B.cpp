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

int a[111], b[111];
int ck = 0;
map<string,bool> q;

int main() {
#ifndef ONLINE_JUDGE
    freopen("119B.in", "r", stdin);
    freopen("119B.out", "w", stdout);
#endif
    int n = read(), k = read();
    foru(i,1,n) read(a[i]);

    bool ok[111];
    fill(ok, true);

    int m = n/k, nQ = read();
    double minf = 1000000000, maxf = -1;
    rep(i, nQ) {
        double s = 0;
        vi v;
        rep(j, m) {
            int x = read();
            s += a[x];
            ok[x] = false;
            v.pb(x);
        }

        string tmp = "";
        sort(all(v));
        rep(i,size(v)) tmp += char(v[i]+int('0'));
        if (q.find(tmp) == q.end()) {
            ++ck;
            q[tmp] = true;
        }

        s /= m;
        minf = min(minf, s);
        maxf = max(maxf, s);
    }
    int c = 0;
    foru(i,1,n)
        if (ok[i]) b[++c] = a[i];

    if (c >= m && ck < k) {
        sort(b+1, b+1+c);
        double s = 0;
        foru(i,1,m) s += b[i];
        s /= m;
        minf = min(minf, s);
        s = 0;
        foru(i,c-m+1,c) s += b[i];
        s /= m;
        maxf = max(maxf, s);
    }
    printf("%.6f %.6f", minf, maxf);
    return 0;
}
