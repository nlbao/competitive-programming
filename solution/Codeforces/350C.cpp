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

const int MAX_N = 100005;

vector<pair<ll, pii> > a;


int main() {
#ifndef ONLINE_JUDGE
    freopen("350C.in", "r", stdin);
    freopen("350C.out", "w", stdout);
#endif
    int n = read(), res = 0;
    rep(i, n) {
        ll x = read(), y = read();
        a.pb( mp(x*x+y*y, mp(x, y)) );
        res += 2 + 2*(x != 0) + 2*(y != 0);
    }
    sort(all(a));

    printf("%d\n", res);
    rep(i, n) {
        int x = a[i].sc.fr, y = a[i].sc.sc;
        if (x < 0) printf("1 %d L\n", -x);
        else if (x > 0) printf("1 %d R\n", x);
        if (y < 0) printf("1 %d D\n", -y);
        else if (y > 0) printf("1 %d U\n", y);
        printf("2\n");
        if (x < 0) printf("1 %d R\n", -x);
        else if (x > 0) printf("1 %d L\n", x);
        if (y < 0) printf("1 %d U\n", -y);
        else if (y > 0) printf("1 %d D\n", y);
        printf("3\n");
    }
    return 0;
}
