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

const int MAX_N = 1000006;

int id[MAX_N];
vi a[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
void read(int &x) {  scanf("%d",&x);    }
void readln(int &x) {   scanf("%d\n",&x);   }

int main() {
#ifndef ONLINE_JUDGE
    freopen("271C.in", "r", stdin);
    freopen("271C.out", "w", stdout);
#endif
    int n = read(), k = read();
    if ((n/k) < 3) {
        cout << -1;
        return 0;
    }

    int p = 0;
    foru(i,1,k-1)
        foru(j,1,3) a[i].pb(++p);
    while (p <= n) a[k].pb(++p);

    for(int i = 1; i < k; i += 2) swap(a[i][0], a[i+1][1]);
    sort(all(a[1]));
    if (k%2 == 1) swap(a[1][0], a[k][1]);

    foru(i,1,k)
        for(int j = 0, sz = size(a[i]); j < sz; ++j)
            id[a[i][j]] = i;
    foru(i,1,n) printf("%d ",id[i]);    cout << endl;
    return 0;
}
