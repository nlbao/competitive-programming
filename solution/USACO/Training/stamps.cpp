/*
    ID: storm59061
    LANG: C++
    TASK: stamps
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

const int MAX_N = 51;
const int MAX_K = 202;
const int MAX_V = 10000;
const int oo = 1000000000;

int n, k, limit;
int a[MAX_N];
int f[MAX_K*MAX_V];

int main() {
#ifndef ONLINE_JUDGE
    freopen("stamps.in", "r", stdin);
    freopen("stamps.out", "w", stdout);
#endif
    scanf("%d%d",&k,&n);
    rep(i,n) scanf("%d",&a[i]);
    limit = k*MAX_V+1;
    foru(i,1,limit) f[i] = oo;
    f[0] = 0;

    sort(a,a+n);
    rep(i,n) {
        int v = a[i];
        rep(x,v)
            if (f[x] == oo) {
                printf("%d\n",x-1);
                return 0;
            }

        foru(x, v, limit)
            f[x] = min(f[x], f[x-v] + 1);
    }
    foru(i,1,limit)
        if (f[i] > k) {
            printf("%d\n",i-1);
            break;
        }
    return 0;
}
