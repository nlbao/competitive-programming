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

int n;
int a[MAX_N], b[MAX_N];

int cal() {
    int i = 0, j = n-1, res = 0;
    while (i <= j) {
        while (i < n && !b[i]) ++i;
        while (j >= 0 && b[j]) --j;
        if (i <= j) {
            res += (i < j);
            ++i;    --j;
        }
    }
    return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("46C.in", "r", stdin);
    freopen("46C.out", "w", stdout);
#endif
    read(n);
    char x;
    scanf("%c",&x);
    rep(i, n) {
        scanf("%c",&x);
        a[i] = (x == 'T');
    }

    int res = n*n;
    rep(i, n) {
        rep(j, n)
            b[j] = a[(j+i)%n];
        res = min(res, cal());
    }
    cout << res;
    return 0;
}
