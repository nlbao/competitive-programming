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

const int MAX_N = 11111;
const int oo = 1000000000;

int a[MAX_N], f[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
#endif
    int nTest = read(), n = 11100;
    rep(test_id, nTest) {
        f[0] = 0;
        foru(i,1,n) f[i] = oo;

        rep(k, 6) {
            read(a[k]);
            foru(i, a[k], n)
                f[i] = min(f[i], f[i-a[k]] + 1);
            ford(i, n-a[k], 0)
                f[i] = min(f[i], f[i+a[k]] + 1);
        }

        rep(k, 6)
            ford(i, n-a[k], 0)
                f[i] = min(f[i], f[i+a[k]] + 1);

        double r1 = 0;
        int r2 = 0;
        foru(i, 1, 100) {
            r1 += f[i];
            r2 = max(r2, f[i]);
        }
        r1 /= 100.0;
        printf("%.2lf %d\n", r1, r2);
    }
    return 0;
}
