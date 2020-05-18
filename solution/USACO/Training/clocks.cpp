/*
    ID: storm59061
    LANG: C++
    TASK: clocks
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

const int MAX_N = 33;
const int move[10][5] = {   {0,0,0,0,0},
                            {1,2,4,5,0},
                            {1,2,3,0,0},
                            {2,3,5,6,0},
                            {1,4,7,0,0},
                            {2,4,5,6,8},
                            {3,6,9,0,0},
                            {4,5,7,8,0},
                            {7,8,9,0,0},
                            {5,6,8,9,0}   };

int nRes = MAX_N;
int a[10];
int res[MAX_N], f[MAX_N];


int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

int mmod(int &x, int c) {
    x = (x+c)%4;
    if (x < 0) x += 4;
    return x;
}

bool check() {
    foru(i,1,9)
        if (a[i] != 0) return false;
    return true;
}

void tryf(int pos, int len) {
    if (len >= nRes) return;
    if (check()) {
        nRes = len;
        foru(i,1,len) res[i] = f[i];
        return;
    }

    if (pos > 9) return;

    ford(c,3,0) {
        foru(i,len+1,len+c) f[i] = pos;
        rep(i,5) mmod(a[move[pos][i]], c);
        tryf(pos+1, len+c);
        rep(i,5) mmod(a[move[pos][i]], -c);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("clocks.in", "r", stdin);
    freopen("clocks.out", "w", stdout);
#endif
    foru(i,1,3)
        foru(j,1,3) {
            int x = read();
            a[3*(i-1)+j] = (x%12)/3;
        }

    tryf(1,0);
    foru(i,1,nRes-1) printf("%d ",res[i]);
    printf("%d\n", res[nRes]);
    return 0;
}
