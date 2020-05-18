/*
    ID: storm59061
    LANG: C++
    TASK: barn1
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

const int MAX_N = 202;

int ok[MAX_N];
vi a;

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
#endif
    int m, s, c;
    scanf("%d%d%d%",&m,&s,&c);
    fill(ok,false);
    rep(i,c) ok[read()] = true;

    int res = 0, n = 0;
    for(int i = 1, pre = 0; i <= s;) {
        while (i <= s && !ok[i]) ++i;
        if (i > s) break;
        int j = i;
        while (j <= s && ok[j]) ++j;
        res += j-i;
        if (pre) a.pb(i-pre);
        i = pre = j;
        ++n;
    }

    sort(all(a));
    int k = size(a);
    rep(i,n-m) res += a[i];
    cout << res << endl;
    return 0;
}
