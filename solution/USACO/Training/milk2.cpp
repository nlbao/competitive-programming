/*
    ID: storm59061
    LANG: C++
    TASK: milk2
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

const int MAX_N = 5003;

pii a[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
#endif
    int n = read();
    rep(i,n) {
        read(a[i].fr);
        read(a[i].sc);
    }
    sort(a,a+n);

    int r1 = 0, r2 = 0, l, r;
    for(int i = 0, j = 0; i < n; i = j) {
        if (i) r2 = max(r2,a[i].fr-r);
        l = a[i].fr, r = a[i].sc;;
        while (j < n && a[j].fr <= r)
            r = max(r,a[j++].sc);
        r1 = max(r1,r-l);
    }
    printf("%d %d\n",r1,r2);
    return 0;
}
