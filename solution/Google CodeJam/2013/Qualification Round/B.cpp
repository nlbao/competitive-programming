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
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

const int MAX_N = 102;

int n, m;
int a[MAX_N][MAX_N];
int row[MAX_N], col[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }

string solve() {
    fill(row,0);
    fill(col,0);
    rep(i,n)
        rep(j,m) {
            row[i] = max(row[i],a[i][j]);
            col[j] = max(col[j],a[i][j]);
        }
    rep(i,n)
        rep(j,m)
            if (row[i] > a[i][j] && col[j] > a[i][j])
                return "NO";
    return "YES";
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("B-large.in", "r", stdin);
    freopen("B.out", "w", stdout);
#endif
    int nTest = read();
    foru(test_id,1,nTest) {
        scanf("%d%d",&n,&m);
        rep(i,n)
            rep(j,m)
                scanf("%d",&a[i][j]);
        cout << "Case #" << test_id << ": " << solve() << endl;
    }
    return 0;
}
