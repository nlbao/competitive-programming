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

const int MAX_N = 10004;

int a[MAX_N], pos[MAX_N];

int read() {   int x;   scanf("%d",&x);   return x;   }
int read(int &x) {  scanf("%d",&x);     return x;   }
int readln(int &x) {   scanf("%d\n",&x);   return x;   }


int main() {
#ifndef ONLINE_JUDGE
    freopen("291D.in", "r", stdin);
    freopen("291D.out", "w", stdout);
#endif
    int n = read(), k = read();
    rep(i,n) {
        pos[i] = n-i;
        a[i] = 1;
    }
    a[n] = 0;

    int pre = (n > 1);
    rep(turn,k) {
        foru(i,1,n)
            if (a[i]+pre >= pos[i]) {
                printf("%d ",pos[pos[i]-a[i]]);
                a[i] = pos[i];
            }
            else {
                printf("%d ",pos[pre]);
                a[i] += pre;
            }
        printf("\n");
        pre = a[1];
    }
    return 0;
}
