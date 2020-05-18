#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<stack>
#define fori(i,a,b) for(int i=a;i<=b;i++)
#define ford(i,a,b) for(int i=a;i>=b;i--)
#define REP(i,N) for(int i=0;i<N;i++)
#define forr(i,a,N) for(int i=a;i<a+N;i++)
#define mp make_pair
#define pb push_back
#define pf push_front
#define sz size()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

inline int read()   {   int x;  scanf("%d", &x);    return x;   }


const int MAX_N = 1e3 + 3;
const int MAX_Q = MAX_N * MAX_N;
const int dx[4] = {-1, 0, +1, 0};
const int dy[4] = {0, +1, 0, -1};
const int oo = 1e9;


int n, m, lq, rq;
int a[MAX_N][MAX_N];
char s[MAX_N];
pii q[MAX_Q], h[MAX_Q];
pii trace[MAX_N][MAX_N];
bool ok[MAX_N][MAX_N];


bool onBoard(int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    return ok[x][y];
}


inline void push(int x, int y) {
    q[++rq] = pii(x, y);
    ok[x][y] = false;
}

inline pii pop() {
    ++lq;
    return q[lq-1];
}


void solve() {
    // init
    int minD = n+m-2;
    memset(ok, true, sizeof(ok));
    lq = 1, rq = 0;
    if (a[1][1] == 1) {
        push(1, 1);
        trace[1][1] = pii(0, 0);
    }
    else {
        int l = 1, r = 1;
        h[1] = pii(1, 1);
        while (l <= r) {
            pii u = h[l++];
            int x = u.first, y = u.second;
            for (int k = 0; k < 4; ++k) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (onBoard(xx, yy) && a[xx][yy] == 0) {
                    ok[xx][yy] = false;
                    int d = (n-xx) + (m-yy);
                    minD = min(minD, d);
                    h[++r] = pii(xx, yy);
                }
            }
        }
        for (int i = 1; i <= r; ++i) {
            pii u = h[i];
            int x = u.first, y = u.second;
            if ((n-x)+(m-y) == minD) {
                push(x, y);
                trace[x][y] = pii(0, 0);
            }
        }
    }

    // bfs
    while (lq <= rq) {
        --minD;
        int l = lq, r = rq;
        int minA = 1;
        while (lq <= r) {
            pii u = pop();
            int x = u.first, y = u.second;
            if (x == n && y == m) return;
            for (int k = 0; k < 4; ++k) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (!onBoard(xx, yy)) continue;
                if ((n-xx)+(m-yy) != minD) continue;
                minA = min(minA, a[xx][yy]);
            }
        }
        lq = l;
        while (lq <= r) {
            pii u = pop();
            int x = u.first, y = u.second;
            for (int k = 0; k < 4; ++k) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (!onBoard(xx, yy)) continue;
                if (a[xx][yy] > minA) continue;
                if ((n-xx)+(m-yy) != minD) continue;
                push(xx, yy);
                trace[xx][yy] = pii(x, y);
                if (xx == n && yy == m) return;
            }
        }
    }
}


void printAns(int x, int y) {
    if (x < 1 || y < 1) return;
    pii u = trace[x][y];
    int xx = u.first, yy = u.second;
    if (xx < 1 && a[x][y] == 0) {
        if (x == n && y == m) printf("0");
        return;
    }
    printAns(xx, yy);
    printf("%d", a[x][y]);
}


int main() {
    int nTest = read();
    while (nTest--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%s", s);
            for (int j = 0; j < m; ++j)
                a[i+1][j+1] = s[j] - '0';
        }
        solve();
        printAns(n, m);
        printf("\n");
    }
}