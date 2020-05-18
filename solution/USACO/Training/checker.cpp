/*
    ID: storm59061
    LANG: C++
    TASK: checker
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

const int MAX_N = 14;

int n, nRes = 0, nPrinted = 0;
int col, dleft, dright;
int f[MAX_N];

int test_bit(int x, int i) { return x & (1 << i);   }

void set_bit(int &x, int i) {   x |= (1 << i);  }

void clear_bit(int &x, int i) { x &= ~(1 << i); }

void tryf(int row, int lim) {
    if (row > n) {
        if (nPrinted++ < 3) {
            foru(i,1,n-1) printf("%d ",f[i]);
            printf("%d\n", f[n]);
        }
        ++nRes;
        if (n > 6 && f[1] <= n/2) ++nRes;
        return;
    }

    foru(i,1,lim) if (!test_bit(col,i)) {
        int l = row-i + n, r = row+i;
        if (test_bit(dleft,l) || test_bit(dright,r)) continue;

        f[row] = i;
        set_bit(col,i);
        set_bit(dleft,l);
        set_bit(dright,r);
        tryf(row+1,n);
        clear_bit(col,i);
        clear_bit(dleft,l);
        clear_bit(dright,r);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("checker.in", "r", stdin);
    freopen("checker.out", "w", stdout);
#endif
    read(n);
    col = dleft = dright = 0;
    tryf(1, n>6?(n+1)/2:n);
    cout << nRes << endl;
    return 0;
}
