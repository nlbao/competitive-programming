#include <sstream>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <utility>
#include <queue>
#include <deque>
#pragma comment(linker, "/STACK:16777216")

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
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

const int MAX_N = 333333;

ll row[MAX_N], col[MAX_N];
char s[100];


int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("ROWCOLOP.in", "r", stdin);
    freopen("ROWCOLOP.out", "w", stdout);
#endif
    int n = read(), q = read();
    fill(row,0);
    fill(col,0);
    rep(i,q) {
        scanf("%s",&s);
        int id = read(), x = read();
        if (s[0] == 'R') row[id] += ll(x);
        else col[id] += x;
    }
    ll maxR = 0, maxC = 0;
    foru(i,1,n) {
        maxR = max(maxR, row[i]);
        maxC = max(maxC, col[i]);
    }
    cout << maxR+maxC;
    return 0;
}
