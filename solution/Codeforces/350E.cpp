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

const int MAX_N = 333;

int a[MAX_N];
bool ok[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("350E.in", "r", stdin);
    freopen("350E.out", "w", stdout);
#endif
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    if (k == n) {
        printf("-1\n");
        return 0;
    }

    fill(ok, false);
    rep(i, k) {
        scanf("%d", &a[i]);
        ok[a[i]] = true;
    }

    int tmp = 2 + n-k-1 + n-3 + ((n-2)*(n-3))/2;
    if (m > tmp) {
        printf("-1\n");
        return 0;
    }

    int u, v;
    foru(i,1,n)
        if (!ok[i]) {
            u = i;
            break;
        }

    printf("%d %d\n", a[0], u);
    printf("%d %d\n", u, a[1]);
    m -= 2;

    foru(i,1,n)
        if (i != a[0] && i != u)
            foru(j,i+1,n) {
                if (m < 1) return 0;
                if (j != a[0] && j != u) {
                    printf("%d %d\n", i, j);
                    --m;
                }
            }

    foru(i,1,n) {
        if (m < 1) return 0;
        if (!ok[i] && i != u) {
            printf("%d %d\n", a[0], i);
            --m;
        }
    }

    foru(i,1,n) {
        if (m < 1) return 0;
        if (i != u && i != a[0] && i != a[1]) {
            printf("%d %d\n", u, i);
            --m;
        }
    }
    return 0;
}
