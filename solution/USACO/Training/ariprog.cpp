/*
    ID: storm59061
    LANG: C++
    TASK: ariprog
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

const int MAX_N = 125004;

int n, m;
vii res;
bool ok[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
#endif
    scanf("%d%d",&n,&m);
    fill(ok,false);
    rep(i,m+1)
        rep(j,m+1)
            ok[i*i+j*j] = true;

    /*rep(i,2*m*m+1)
        if (ok[i]) cout << i << " ";
    cout << endl;*/

    int limit = 2*m*m;
    foru(a,0,limit) if (ok[a])
        foru(b,1,limit) {
            if (a+(n-1)*b > limit) break;
            bool ck = true;
            int x = a;
            for(int i = 0, x = a; i < n; ++i, x += b)
                if (!ok[x]) {
                    ck = false;
                    break;
                }
            if (ck) res.pb(mp(b,a));
        }
    sort(all(res));

    m = size(res);
    if (m == 0) printf("NONE\n");
    else rep(i,m) printf("%d %d\n",res[i].sc,res[i].fr);
    return 0;
}
