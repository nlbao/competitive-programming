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

const int MAX_N = 2503;
const int L = 2000006;

int a[MAX_N];
int f[MAX_N][MAX_N];
int t[2*L], pos[2*L];

int main() {
#ifndef ONLINE_JUDGE
    freopen("SKFIB.in", "r", stdin);
    freopen("SKFIB.out", "w", stdout);
#endif
    int nTest = read(), time = 1;
    fill(t, 0);
    rep(test_id, nTest) {
        int n = read();
        rep(i, n) read(a[i]);

        int res = 2;
        ford(i, n-2, 0) {
            ++time;
            ford(j, n-1, i+1) {
                int x = a[i]+a[j]+L;
                if (t[x] == time) {
                    f[i][j] = f[j][pos[x]] + 1;
                    res = max(res, f[i][j]);
                }
                else
                    f[i][j] = 2;
                x = a[j]+L;
                t[x] = time;
                pos[x] = j;
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
