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

const int MAX_N = 1003;

int n, m;
bool row[MAX_N], col[MAX_N];


int main() {
#ifndef ONLINE_JUDGE
    freopen("333B.in", "r", stdin);
    freopen("333B.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    if (n < 3) {
        cout << 0;
        return 0;
    }
    fill(row,true);
    fill(col,true);
    row[1] = col[1] = row[n] = col[n] = false;
    rep(i,m) {
        int x = read(), y = read();
        row[x] = false;
        col[y] = false;
    }

    int res = 0;
    foru(i,1,n) res += int(row[i]) + int(col[i]);
    if (n%2 == 1) {
        int mid = (n+1)/2;
        if (row[mid] && col[mid]) --res;
    }
    cout << res;
    return 0;
}
