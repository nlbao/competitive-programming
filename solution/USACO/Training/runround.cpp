/*
    ID: storm59061
    LANG: C++
    TASK: runround
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


void swap(int &x, int &y) {
    int t = x;
    x = y;
    y = t;
}

bool check(ll n) {
    int len = 0;
    int a[10];
    while (n) {
        a[len++] = n%10;
        n /= 10;
    }
    for(int i = 0, j = len-1; i < j; ++i, --j) swap(a[i], a[j]);
    rep(i,len-1)
        foru(j,i+1,len-1)
            if (a[i] == a[j]) return false;

    int c = 0, i = 0;
    bool visited[10];
    fill(visited, false);
    for(; c < len;) {
        if (visited[i]) return false;
        visited[i] = true;
        i = (i+a[i])%len;
        ++c;

    }
    return i == 0;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("runround.in", "r", stdin);
    freopen("runround.out", "w", stdout);
#endif
    ll n;
    scanf("%lld",&n);
    for(;;)
        if (check(++n)) {
            printf("%lld\n",n);
            break;
        }
    return 0;
}
