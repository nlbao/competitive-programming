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

const int MAX_N = 100005;
const int M = 32;

ll f[M+4][2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("PPXOR_test.in", "r", stdin);
    freopen("PPXOR.out", "w", stdout);
#endif
    int nTest = read();
    rep(test_id, nTest) {
        int n = read();
        ll s = 0, res = 0;
        rep(i, M) {
            f[i][0] = 1;
            f[i][1] = 0;
        }

        rep(id, n) {
            ll a = read();
            s ^= a;
            rep(i, M) {
                int x = (s>>i)&1;
                res += (1LL<<i)*f[i][1-x];
                ++f[i][x];
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
