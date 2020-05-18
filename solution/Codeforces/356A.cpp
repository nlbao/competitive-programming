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

const int MAX_N = 3*100005;

int pnext[MAX_N], pre[MAX_N], res[MAX_N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("356A.in", "r", stdin);
    freopen("356A.out", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);

    fill(res, 0);
    foru(i,1,n) {
        pnext[i] = i+1;
        pre[i] = i-1;
    }

    rep(id, m) {
        int l, r, x;
        scanf("%d%d%d", &l ,&r, &x);

        int i = l;
        bool found_x = false;
        while (i <= r) {
            int j = pnext[i];
            if (i == x) found_x = true;
            else {
                if (res[i] == 0) res[i] = x;
                if (found_x) {
                    pnext[x] = pnext[i];
                    pre[i] = pre[pnext[i]] = x;
                }
                else {
                    pre[x] = pre[i];
                    pnext[i] = pnext[pre[i]] = x;
                }
            }
            i = j;
        }
    }

    foru(i,1,n) printf("%d ", res[i]);
    return 0;
}
