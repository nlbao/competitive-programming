/*
    ID: storm59061
    LANG: C++
    TASK: concom
*/
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

const int MAX_N = 102;

int a[MAX_N][MAX_N], f[MAX_N][MAX_N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("concom.in", "r", stdin);
    freopen("concom.out", "w", stdout);
#endif
    fill(a,0);
    int m = read(), n = 0;
    rep(i,m) {
        int x = read(), y = read();
        read(a[x][y]);
        n = max(n,max(x,y));
    }

    fill(f,0);
    foru(i,1,n) {
        queue<int> q;
        bool in_q[MAX_N] = {false};
        q.push(i);
        in_q[i] = true;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            foru(v,1,n) {
                f[i][v] += a[u][v];
                if (!in_q[v] && f[i][v] > 50) {
                    q.push(v);
                    in_q[v] = true;
                }
            }
        }
        f[i][i] = 0;
    }

    foru(i,1,n)
        foru(j,1,n)
            if (f[i][j] > 50)
                printf("%d %d\n",i,j);
    return 0;
}
